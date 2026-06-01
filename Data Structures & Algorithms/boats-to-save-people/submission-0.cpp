class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int ans = 0;
        while(left <= right)
        {
            int sum = people[left] + people[right];
            if(sum <= limit)
            {
                left++;
                right--;
                ans++;
            }
            else
            {
                right--;
                ans++;
            }
        }
        return ans;
    }
};