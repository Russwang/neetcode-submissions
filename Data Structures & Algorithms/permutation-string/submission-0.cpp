class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> count(26, 0);
        vector<int> validate(26, 0);
        int left = 0, right = 0;
        for (char chr:s1) count[chr - 'a']++;

        // for (char chr:s2) {
        //     validate[chr- 'a']++;
        //     if (right - left + 1 == s1.length()) {
        //         if (count == validate) return true;
        //     } else {
        //         validate[s2[left] - 'a']--;
        //         left++;
        //     }
        //     right++;
        // }

        for (int i = 0; i < s2.length(); i++) {
            validate[s2[i] - 'a']++;
            if (i - left + 1 == s1.length()) {
                if (count == validate) return true;
                validate[s2[left] - 'a']--;
                left++;
            }
        }

        return false;
    }
};
