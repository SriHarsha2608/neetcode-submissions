class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            
            if(s[i] == ']') {

                string str = "";

                while(st.top() != "[") {
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();
                
                string k = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }

                int count = stoi(k);

                string repeated = "";
                for(int i = 0; i < count; i++) {
                    repeated += str;
                }

                st.push(repeated);

            } else {
                st.push(string(1, s[i]));
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};