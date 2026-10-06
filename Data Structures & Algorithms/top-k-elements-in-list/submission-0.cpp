class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size()  + 1);
        unordered_map<int,int> counter;

        for (int num:nums) counter[num]++;
        for (auto& [num,count]: counter) {
            bucket[count].push_back(num);
        }

        vector<int> res;
        for (int i = nums.size(); i >= 0 && res.size() < k; i--) {
            for (auto b:bucket[i]) {
                res.push_back(b);
            }
        }

        return res;
    }
};

