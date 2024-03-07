#include "ContextGrep.h"

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

// Comparator to check if a match index is not equal to the current index
struct MatchIndexComparator {
    size_t currentIndex;

    MatchIndexComparator(size_t currentIndex) : currentIndex(currentIndex) {}

    bool operator()(const pair<size_t, string>& matchIndex) const {
        return matchIndex.first != currentIndex;
    }
};

// Constructor to initialize file path, pattern, and context size
ContextGrep::ContextGrep(const string& filePath, const string& pattern, size_t contextSize)
    : filePath(filePath), pattern(pattern), contextSize(contextSize) {}

// Read lines from the file and return them as a vector
vector<string> ContextGrep::readLines() const {
    vector<string> lines;
    ifstream file(filePath);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filePath << endl;
    }

    return lines;
}

// Get context lines around the current match index
vector<string> ContextGrep::getContextLines(size_t currentIndex, size_t& lastMatchEnd, const vector<string>& lines, const vector<pair<size_t, string>>& matches) const {
    // Initialize start and end indices for context lines
    size_t startIndex = max(static_cast<int>(currentIndex - contextSize), 0);
    size_t endIndex = min(lines.size(), currentIndex + contextSize + 1);

    // Iterator to find the next match index
    auto it = find_if(matches.begin(), matches.end(), MatchIndexComparator(currentIndex));
 
    size_t nextMatchIndex = 0;
    // Loop through overlapping match indices
    while (it != matches.end() ) {
        nextMatchIndex = it->first;
        //cout << "nextMatchIndex: " << nextMatchIndex << " startIndex: " << startIndex << ", endIndex: " << endIndex << endl;

	if ( nextMatchIndex > currentIndex )
        {
	    if ( endIndex - 1 >= nextMatchIndex )
            {
                // Adjust endIndex based on the overlap logic
                endIndex = min(nextMatchIndex + contextSize + 1, lines.size());
		currentIndex = nextMatchIndex;
                //cout << "new endIndex: " << endIndex << endl;
	    }
 	    else
                break;
	}

    	it = find_if(it, matches.end(), MatchIndexComparator(nextMatchIndex));
    }

    // Set the lastMatchEnd and return context lines
    lastMatchEnd = endIndex - 1;
    return {lines.begin() + startIndex, lines.begin() + endIndex};
}

// Search for matches and return context lines
vector<string> ContextGrep::search() const {
    vector<string> matches;
    size_t lastMatchEnd = 0;
    const auto lines = readLines();

    vector<pair<size_t, string>> matchIndices;

    // Find indices of lines containing the specified pattern
    for (size_t i = 0; i < lines.size(); ++i) {
        if (lines[i].find(pattern) != string::npos) {
            matchIndices.emplace_back(i, lines[i]);
        }
    }

    // Iterate through matches and collect context lines
    for (const auto& matchIndex : matchIndices) {
	if ( lastMatchEnd == 0 || matchIndex.first >= lastMatchEnd + 1 ) {
            if ( lastMatchEnd != 0 ) {
                // Add a separator line after each set of matches
                matches.push_back("----------------");
            }
            auto contextLines = getContextLines(matchIndex.first, lastMatchEnd, lines, matchIndices);
            matches.insert(matches.end(), contextLines.begin(), contextLines.end());
	}
    }

    return matches;
}

// Print matched lines with context to the console
void ContextGrep::printMatches(const vector<string>& matches) {
    for (const auto& line : matches) {
        cout << line << endl;
    }
}

