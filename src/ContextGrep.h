#ifndef CONTEXTGREP_H
#define CONTEXTGREP_H

#include <vector>
#include <string>
#include <utility>

using namespace std;

class ContextGrep {
public:
    ContextGrep(const string& filePath, const string& pattern, size_t contextSize);

    vector<string> readLines() const;
    vector<string> getContextLines(size_t currentIndex, size_t& lastMatchEnd, const vector<string>& lines, const vector<pair<size_t, string>>& matches) const;
    vector<string> search() const;
    void printMatches(const vector<string>& matches);

private:
    string filePath;
    string pattern;
    size_t contextSize;
};

#endif // CONTEXTGREP_H

