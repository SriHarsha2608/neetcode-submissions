class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber > 0)
        {
            columnNumber--;
            int letterNumber = columnNumber % 26;
            ans += letterNumber + 'A';

            columnNumber /= 26;
        }

        // reverse(ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};