class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string str: operations)
        {
            
                if(str == "+")
                {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();

                    st.push(num1);
                    st.push(num1 + num2);
                }
                else if(str == "C")
                {
                    st.pop();
                }
                else if(str == "D")
                {
                    int num = st.top();
                    st.push(num * 2);
                }
                else
                {
                    st.push(stoi(str));
                }
            
        }

        int sum = 0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};