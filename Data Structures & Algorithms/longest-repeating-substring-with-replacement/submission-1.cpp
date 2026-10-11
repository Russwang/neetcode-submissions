class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, len = s.length();
        vector<int> counter(26, 0);
        int curmax = 0, res = 0;

        for (int i = 0; i < len; i++) {
            int chr = s[i] - 'A';
            counter[chr]++;
            curmax = max(curmax, counter[chr]);

            if (i - left + 1 - curmax > k) {
                while (i - left + 1 - curmax > k) {
                    counter[s[left] - 'A']--;
                    left++;
                }
            }

            res = max(res, i - left + 1);
            
        }

        return res;
    }
};
