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

        

        // for (int i = 0; i < size; i++) {
        //     int left = i, right = i;
        //     int height = heights[i], width = 0;

        //     while (left >= 0 and heights[left] >= height) left--;
        //     while (right < size and heights[right] >= height) right++;
        //     width = right - left - 1;

        //     res = max(res, height * width);
        // }

        return res;
    }
};
