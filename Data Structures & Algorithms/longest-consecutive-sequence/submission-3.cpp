class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int num) {
        if (parent[num] != num) {
            parent[num] = find(parent[num]);
        }
        return parent[num];
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        if (rank[pa] == rank[pb]) {
            parent[pb] = pa;
            rank[pa]++;
        } 
        else if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } 
        else {
            parent[pa] = pb;
        }
    }

    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0) return 0;
        unordered_map<int,int> map;
        int i = 0; 
        int size = nums.size();
        int res = 1;

        parent = vector<int> (size, 0);
        // rank = vector<int> (size, 0);
        vector<int> length(size, 1);
        

        for (int i = 0; i < size; i++) {
            if (map.find(nums[i]) != map.end()) continue;
            map[nums[i]] = i;
            parent[i] = i;

            if (map.find(nums[i] - 1) != map.end()) {
                int pa = find(i), pb = find(map[nums[i] - 1]);
                if (pa != pb) {
                    parent[pa] = pb;
                    length[pb] += length[pa];
                }
                res = max(res, length[pb]);
            }
            if (map.find(nums[i] + 1) != map.end()) {
                int pa = find(i), pb = find(map[nums[i] + 1]);
                if (pa != pb) {
                    parent[pb] = pa;
                    length[pa] += length[pb];
                }
                res = max(res, length[pa]);
            }
        }
        

        return res;
    }
};




