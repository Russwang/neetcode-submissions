class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counter(26, 0);
        for (auto c:s) counter[c - 'a']++;
        for (auto c:t) {
            if (--counter[c - 'a'] < 0) return false;
        }
        for (int i:counter) if (i) return false;
        return true;
    }
};
