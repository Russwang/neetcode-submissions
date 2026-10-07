class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int size = temp.size();
        vector<int> res(size, 0);

        for (int i = size - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < size && temp[j] <= temp[i]) {
                if (res[j] == 0) {
                    j = size;
                    break;
                }
                j = j + res[j];
            }

            if (j < size) {
                res[i] = j - i;
            }
        }

        return res;
    }
};
