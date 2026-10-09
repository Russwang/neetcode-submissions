class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int res = 0;

        while (left < right) {
            int area = (right - left) * (min(heights[left], heights[right]));

            res = max(res, area);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};
