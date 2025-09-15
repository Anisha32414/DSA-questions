class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0); // Frequency array for 'a' to 'z'
        string vowels = "aeiou";
    
    // Count frequency of each letter
        for (char c : s) {
           freq[c - 'a']++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

    // Check each letter
        for (int i = 0; i < 26; i++) {
           char c = 'a' + i;
           if (vowels.find(c) != string::npos) {
            // It's a vowel
               maxVowel = max(maxVowel, freq[i]);
           } else {
            // It's a consonant
               maxConsonant = max(maxConsonant, freq[i]);
            }
        }

        return maxVowel + maxConsonant;
    }
};
