class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 0;
        int size = position.size();
        stack<double> st;
        vector<pair<int,int>> cars;

        for (int i = 0; i < size; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        for (int i = 0; i < size; i++) {
            double cur_time = double(target - cars[i].first) / cars[i].second;

            if (st.empty()) {
                st.push(cur_time);
                continue;
            }

            if (cur_time <= st.top()) continue;
            st.push(cur_time);
            
        }

        

        return st.size();
    }
};
