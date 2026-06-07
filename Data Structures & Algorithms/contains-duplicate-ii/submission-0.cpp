class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0, right = 0;

        unordered_set<int> st;

        for(int right = 0; right < nums.size(); right++)
        {
            if(right - left > k)
            {
                st.erase(nums[left]);
                left++;
            }

            if(st.find(nums[right]) != st.end())
            {
                return true;
            }

            st.insert(nums[right]);
        }

        return false;
    }
}; 