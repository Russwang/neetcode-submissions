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
        if (rank[pa] == rank[pb]) {
            parent[pb] = pa;
            rank[pa]++;
        } 
        else if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
            rank[pa]++;
        } 
        else {
            parent[pa] = pb;
            rank[pb]++;
        }
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> counter;
        for (int num:nums) counter[num]++;
        
        int res = 0;
        for (auto& [num, count]: counter) {
            if (count == 0) continue;
            int length = 1;
            int left = num, right = num;
            while (counter.find(left - 1) != counter.end()) {
                counter[left - 1] = 0;
                length++; 
                left--;
            }
            while (counter.find(right + 1) != counter.end()) {
                counter[right + 1] = 0;
                length++;
                right++;
            }
            res = max(res ,length);
        }

        return res;
    }
};




