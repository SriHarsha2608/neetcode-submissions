class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = digits[digits.size() - 1] + 1;
        int carry = sum / 10;
        digits[digits.size() - 1] = sum % 10;

        for(int i = digits.size() - 2; i >= 0 && carry > 0; i--)
        {
            int insideSum = digits[i] + carry;

            digits[i] = insideSum % 10;
            carry = insideSum / 10;
        }

        if(carry > 0)
        {
            reverse(digits.begin(), digits.end());
            digits.push_back(1);
            reverse(digits.begin(), digits.end());
        }

        return digits;
    }
};
