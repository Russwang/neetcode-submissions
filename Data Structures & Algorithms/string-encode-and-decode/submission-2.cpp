class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string str:strs) {
            res = res + to_string(str.length());
            res += '#';
            res.append(str);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int right = 0;
        while (right < s.length()) {
            int left = right;
            while (s[right] != '#') right++;
            int len = stoi(s.substr(left, right - left));
            right++;
            res.push_back(s.substr(right, len));
            right += len;
        }
        return res;
    }
};
