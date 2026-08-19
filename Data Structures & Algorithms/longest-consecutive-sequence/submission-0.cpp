class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        for(int num: st) {
            if(st.find(num - 1) == st.end()) {
                int len = 1;
                while(st.find(num + len) != st.end()) {
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};
