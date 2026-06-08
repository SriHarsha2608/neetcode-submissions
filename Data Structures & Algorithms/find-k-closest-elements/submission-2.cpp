class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        int left = index - 1, right = index;

        while(right - left - 1 < k)
        {
            if(left >= 0 && right < arr.size())
            {
                if(abs(arr[left] - x) <= abs(arr[right] - x))
                {
                    left--;
                }
                else
                {
                    right++;
                }
            }

            else if(left >= 0)
            {
                left--;
            }
            else
            {
                right++;
            }

        }

        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};