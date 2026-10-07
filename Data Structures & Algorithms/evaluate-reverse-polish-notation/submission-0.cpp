class Solution {
public:

    bool isOperator(string c) {
        if (c == "+" || c == "-" || c == "*" || c == "/") return true;
        return false;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            if (isOperator(tokens[i])) {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                string c = tokens[i];

                if (c == "+") left += right;
                else if (c == "-") left -= right;
                else if (c == "*") left *= right;
                else left /= right;
                nums.push(left);
            } 
            else {
                nums.push(stoi(tokens[i]));
            }
        }

        return nums.top();
    }
};
