class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char c : s) 
        {
            if (isalnum(c)) 
            {
                str += tolower(c);
            }
        }
        int n = str.size();

        int left = 0, right = n - 1;
        while(left < right)
        {
            if(str[left] != str[right])
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
