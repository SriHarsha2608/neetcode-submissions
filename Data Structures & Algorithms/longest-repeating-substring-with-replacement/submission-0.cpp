class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int ans = 0;
        int maxFreq = 0;
        map<char, int> mpp;
        while(right < s.size())
        {
            mpp[s[right]]++;
            maxFreq = max(maxFreq, mpp[s[right]]);

            while(right - left + 1 - maxFreq > k)
            {
                mpp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
};
