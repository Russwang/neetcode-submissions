class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size();
        vector<int> res(size, -1);
        stack<int> st;

        unordered_map<int,int> mapping;
        for (int i = 0; i < size; i++) mapping[nums1[i]] = i;

        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                if (mapping.find(st.top()) == mapping.end()) {
                    st.pop();
                    continue;
                } else {
                    res[mapping[st.top()]] = nums2[i];
                    st.pop();
                }
            }

            st.push(nums2[i]);
        }

        return res;
    }
};