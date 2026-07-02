class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int asteroid: asteroids)
        {
            if(asteroid > 0)
            {
                st.push(asteroid);
            }
            else
            {
                while(!st.empty() && st.top() > 0 && abs(asteroid) > st.top())
                {
                    st.pop();
                }
                if(st.empty())
                {
                    st.push(asteroid);
                }
                else
                {
                    if(abs(asteroid) == st.top())
                    {
                        st.pop();
                    }
                    else if(abs(asteroid) > st.top())
                    {
                        st.push(asteroid);
                    }
                }
            }
        }

        vector<int> ans;

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};