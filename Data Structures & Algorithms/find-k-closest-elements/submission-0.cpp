class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        int left = index - 1, right = index;

        vector<int> ans;
        while(k--)
        {
            if(left >= 0 && right < arr.size())
            {
                if(abs(arr[left] - x) <= abs(arr[right] - x))
                {
                    ans.push_back(arr[left]);
                    left--;
                }
                else
                {
                    ans.push_back(arr[right]);
                    right++;
                }
            }

            else if(left >= 0)
            {
                ans.push_back(arr[left]);
                left--;
            }
            else
            {
                ans.push_back(arr[right]);
                right++;
            }

        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};