class Solution {
public:

    bool isOpen(char c) {
        if (c == '[' || c == '{' || c == '(') return true;
        return false;
    }

    bool isValid(string s) {
        stack<char> st;


        for (auto c:s) {
            if (isOpen(c)) st.push(c);
            else {
                if (st.empty()) return false;
                if (c == ']') {
                    if (st.top() != '[') return false;
                }
                else if (c == '}') {
                    if (st.top() != '{') return false;
                }
                else if (st.top() != '(') return false;
                st.pop();
            }
        }

        if (st.size()) return false;

        return true;
    }
};
