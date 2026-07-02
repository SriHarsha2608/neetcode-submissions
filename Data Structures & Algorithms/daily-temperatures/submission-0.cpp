class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> nextGreatest(n, -1);

        for(int i = n - 1; i >= 0; i--)
        {            
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                nextGreatest[i] = st.top();
            }

            st.push(i);
        }

        for(int i = 0; i < n; i++)
        {
            if(nextGreatest[i] == -1)
            {
                nextGreatest[i] = 0;
            }
            else
            {
                nextGreatest[i] -= i;
            }
        }

        return nextGreatest;
    }
};
