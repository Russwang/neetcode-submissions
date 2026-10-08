class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (right > left && !isalnum(s[right])) right--;
            if (left >= right) return true;

            if (isalpha(s[left])) {
                if (!isalpha(s[right]) || tolower(s[left]) != towlower(s[right])) {
                    return false;
                }
            }
            if (isdigit(s[left])) {
                if (!isdigit(s[right]) || s[left] != s[right]) return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
