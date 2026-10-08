class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int size = heights.size();

        vector<int> left(size, -1);
        vector<int> right(size, size);

        stack<int> st;

        for (int i = 0; i < size; i++) {
            while (st.size() and heights[i] < heights[st.top()]) {
                right[st.top()] = i;
                st.pop();
            }

            if (!st.empty()) {
                left[i] = st.top();
            }

            st.push(i);
        }

        for (int i = 0; i < size; i++) {
            int height = heights[i];
            int width = right[i] - left[i] - 1;
            res = max(res, height * width);
        }

        


        return res;
    }
};
