class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> counter;
        int len = 0;
        int left = 0;

        for (int i = 0; i < s.length(); i++) {
            
            while (counter[s[i]] != 0) {
                counter[s[left]]--;
                left++;
            }
            counter[s[i]]++;
            len = max(len, i - left + 1);
        } 

        return len;
    }
};
