class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        // int last = 0;
        int res = 0;
        int cur = 0;
        stack<int> st;

        cout << "checkpoint -1" << endl;

        while (left + 1 < height.size() && height[left] <= height[left + 1]) left++;
        st.push(left);
        // last = left;

        cout << "checkpoint 0" << endl;

        for (int i = left + 1; i< height.size(); i++) {
            if (height[i] < height[left]) {
                st.push(i);
            } 
            else {
                int h = height[left];
                while (st.size()) {
                    res += h - height[st.top()];
                    st.pop();
                }
                st.push(i);
                left = i;
            }
        }

        cout << "checkpoint 1" << endl;

        int right = 0;        
        while (st.size() >= 2) {
            int top = st.top();
            st.pop();
            if (height[top] <= height[st.top()]) continue;
            else {
                right = top;
                break;
            }
        }

        cout << "checkpoint 2" << endl;

        while (st.size()) {
            if (height[st.top()] < height[right]) {
                res += height[right] - height[st.top()];
                st.pop();
            } else {
                right = st.top();
                st.pop();
            }
        }
        
    
        return res;
    }
};
