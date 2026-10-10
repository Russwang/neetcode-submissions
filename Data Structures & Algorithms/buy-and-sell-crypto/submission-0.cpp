class Solution {
public:
    int maxProfit(vector<int>& price) {
        
        int curmin = price[0], res = 0;

        for (int i = 0; i < price.size(); i++) {
            if (price[i] > curmin) res = max(res, price[i] - curmin);
            else curmin = price[i];
        }

        return res;

    }
};
