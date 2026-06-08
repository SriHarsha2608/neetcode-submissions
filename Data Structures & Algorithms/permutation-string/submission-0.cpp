class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
        {
            return false;
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(int i = 0; i < s1.size(); i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        int count = 0;
        for(int i = 0; i < 26; i++)
        {
            if(freq1[i] == freq2[i])
            {
                count++;
            }
        }

        int left = 0;

        for(int right = s1.size(); right < s2.size(); right++)
        {

            if(count == 26)
            {
                return true;
            }

            int index = s2[right] - 'a';
            freq2[index]++;

            if(freq1[index] == freq2[index])
            {
                count++;
            }
            else if(freq1[index] + 1 == freq2[index])
            {
                count--;
            }

            index = s2[left] - 'a';
            freq2[index]--;

            if(freq1[index] == freq2[index])
            {
                count++;
            }
            else if(freq1[index] - 1 == freq2[index])
            {
                count--;
            }
            left++;
        }

        return count == 26;
    }
};
