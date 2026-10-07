class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tempretures) {
        int size = tempretures.size();
        vector<int> res(size, 0);
        stack<pair<int,int>> st; // <temp, pos> 

        for (int i = 0; i < size; i++) {
            if (st.empty()) {
                st.push({tempretures[i], i});
                continue;
            }
            if (st.top().first >= tempretures[i]) {
                st.push({tempretures[i], i});
            } else {
                while (!st.empty() and st.top().first < tempretures[i]) {
                    int pos = st.top().second;
                    int temp = st.top().first;
                    st.pop();
                    res[pos] = i - pos;
                }
                st.push({tempretures[i], i});
            }
        }

        return res;
    }
};