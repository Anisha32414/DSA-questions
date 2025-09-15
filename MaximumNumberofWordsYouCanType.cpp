class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    set<char> brokenSet;
    for (char c : brokenLetters) {
        brokenSet.insert(c);
    }

    istringstream iss(text);
    string word;
    int count = 0;

    while (iss >> word) {
        bool canType = true;
        for (char c : word) {
            if (brokenSet.find(c) != brokenSet.end()) {
                canType = false;
                break;
            }
        }
        if (canType) {
            count++;
        }
    }

    return count;
    }
};
