class Solution {
public:
    int sumOfSquares(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int digit = n % 10;
            n /= 10;

            sum += digit * digit;
        }

        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(true)
        {
            int sum = sumOfSquares(n);

            if(sum == 1)
            {
                return true;
            }
            else
            {
                if(st.find(sum) == st.end())
                {
                    st.insert(sum);
                    n = sum;
                }
                else
                {
                    return false;
                }
            }
        }

    }
};
