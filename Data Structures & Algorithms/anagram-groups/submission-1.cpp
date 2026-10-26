class Solution {
public:
    // & after the type = pass by reference, so the whole vector isn't copied
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map = hash table, avg O(1) lookups
        // key = the letter-count signature, value = all strings sharing it
        unordered_map<string, vector<string>> res;

        // const auto& = read-only and no copy, the usual idiom for looping
        for (const auto& s : strs) {
            vector<int> count(26, 0); // Initialize array of size 26 where each element is 0
            // Useful for counting frequency of letters in English
            for (char c : s) {
                count[c - 'a']++;   // Using a as the lowest ascii value we can subtract the ascii
                // value of a in order to map the characters i.e
                // a - a = 0 | b - a = 1 ... z - a = 25
            }
            string key = to_string(count[0]); // to_string turns an int into a string
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]); // comma keeps (1, 11) and (11, 1) from colliding
            }
            // [] creates an empty vector if the key is new, so this works for both cases
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second); // pair.first = key, pair.second = the group
        }
        return result;
    }
};