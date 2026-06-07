class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char,int> mpp;
        int maxLen = 0;
        while(right < s.size())
        {
            if(mpp.find(s[right]) != mpp.end())
            {
                if(left <= mpp[s[right]])
                {
                    left = mpp[s[right]] + 1;
                }
                
            }
            mpp[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};
