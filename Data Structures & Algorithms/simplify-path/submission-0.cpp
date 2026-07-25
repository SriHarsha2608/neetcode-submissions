class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;

        for(int i = 0; i < n; i++) {
            if(path[i] == '/') {
                int j = i;
                while(j < n && path[j] == '/') {
                    j++;
                }

                i = j - 1;

            } else if(path[i] == '.') {
                int j = i;
                while(j < n && path[j] != '/') {
                    j++;
                }

                string folderName = path.substr(i, j - i);

                if(folderName == ".") {
                    // Do Nothing
                } else if(folderName == "..") {
                    if(!st.empty()) st.pop();
                } else {
                    st.push(folderName);
                }
                i = j - 1;

            } else {
                int j = i;
                while(j < n && path[j] != '/') {
                    j++;
                }
                string folderName = path.substr(i, j - i);
                st.push(folderName);

                i = j - 1;
            }
            
        }

        string ans = "";

        while(!st.empty()) {

            ans = "/" + st.top() + ans;
            st.pop();

        }
        
        if(ans.empty()) return "/";
        return ans;

    }
};