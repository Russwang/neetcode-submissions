class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        vector<int> counter(26,0);

        for (const string& str:strs) {
            for (auto c:str) counter[c - 'a']++;

            string key = "";
            string num = "";
            for (int& count:counter) {
                num = to_string(count);
                while (num.length() < 3) num = '0' + num;
                key = key + num;
                count = 0;
            }

            if (map.find(key) != map.end()) map[key].push_back(str);
            else map[key] = {str};
        }

        for (auto& [key,value]: map) res.push_back(value);
        return res;
    }
};
