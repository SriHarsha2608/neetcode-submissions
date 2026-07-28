class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }

        int n = num1.size(), m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> ans(n + m, 0);

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                int digit = (num1[i] - '0') * (num2[j] - '0');
                ans[i + j] += digit;
                ans[i + j + 1] += ans[i + j] / 10;
                ans[i + j] %= 10;

            }
        }

        int i = n + m - 1;
        while(i >= 0 && ans[i] == 0) {
            i--;
        }

        string res;
        while(i >= 0) {
            res += char(ans[i] + '0');
            i--;
        }

        return res;
    }
};
