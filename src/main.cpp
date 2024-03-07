#include "ContextGrep.h"
#include <iostream>
#include <map>

using namespace std;

map<string, string> parseCommandLine(int argc, char* argv[]) {
    map<string, string> options;

    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                options[argv[i]] = argv[i + 1];
                ++i;
            } else {
                options[argv[i]] = ""; // Flag without value
            }
        }
    }

    return options;
}

#ifndef TEST
int main(int argc, char* argv[]) {
    map<string, string> options = parseCommandLine(argc, argv);
   
    int contextSize = 0;
    // For now, option -C only, but should be easily expandable to include other options
    if ( options.find("-C") == options.end() ) {
        cerr << "Usage: " << argv[0] << " -C <context_size> <pattern> <file_path>" << endl;
        return 1;
    }
    else 
    {	    
        if ( options["-C"].empty() )
        {
            return 1;
        } else if ( argc < 5 ) {
            cerr << "Insufficient arguments. Provide both pattern and file_path." << endl;
            return 1;
        }
        else if ( argc > 5 ) {
            cerr << "Too many arguments. Please provide only pattern and file_path." << endl;
            return 1;
        }
    
	contextSize = stoi(options["-C"]);
        if (contextSize < 0) {
            cerr << "Context size cannot be negative." << endl;
            return 1;
        }
    }

    string pattern = argv[argc - 2];
    string filePath = argv[argc - 1];

    ContextGrep contextGrep(filePath, pattern, contextSize );
    auto matches = contextGrep.search();

    if (matches.empty()) {
        cout << "No matches found." << endl;
    } else {
        contextGrep.printMatches(matches);
    }

    return 0;
}
#endif
