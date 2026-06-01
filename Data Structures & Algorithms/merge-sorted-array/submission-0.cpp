class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1, right = n - 1;
        int i = m + n - 1;
        while(left >= 0 && right >= 0)
        {
            if(nums1[left] > nums2[right])
            {
                nums1[i] = nums1[left];
                i--;
                left--;
            }
            else
            {
                nums1[i] = nums2[right];
                i--;
                right--; 
            }
        }
        while(right >= 0)
        {
            nums1[i] = nums2[right];
            i--;
            right--;
        }
    }
};