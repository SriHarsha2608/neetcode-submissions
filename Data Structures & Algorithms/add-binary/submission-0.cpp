class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();

        int i = n - 1, j = m - 1;

        string ans = "";
        int carry = 0;
        while(i >= 0 || j >= 0 || carry > 0)
        {
            int sum = 0;
            if(i >= 0)
            {
                sum += a[i] - '0';
            }

            if(j >= 0)
            {
                sum += b[j] - '0';
            }

            sum += carry;

            ans += (sum % 2) + '0';

            carry = sum / 2;

            i--;
            j--; 
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};