class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int ans = -1;
        while(left < right)
        {
            ans = max(ans, (right - left) * min(heights[left], heights[right]));
            if(heights[left] < heights[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};
