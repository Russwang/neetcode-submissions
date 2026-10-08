class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;

        int left = 0, right = numbers.size() - 1;

        while (numbers[right] + numbers[left] > target) right--;
        if (numbers[right] + numbers[left] == target) return {left + 1, right + 1};

        while (left < right) {
            if (numbers[right] + numbers[left] > target) right--;
            if (numbers[right] + numbers[left] == target) return {left + 1, right + 1};

            if (numbers[left] + numbers[right] < target) left++;
            if (numbers[right] + numbers[left] == target) return {left + 1, right + 1};
        }

        return {};
    }
};
