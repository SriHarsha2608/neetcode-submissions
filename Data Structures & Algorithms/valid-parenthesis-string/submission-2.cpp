class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;

        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] == '(') {

                mini += 1;
                maxi += 1;

            } else if(s[i] == ')') {

                mini -= 1;
                maxi -= 1;
                if(maxi < 0) {
                    return false;
                }

            } else {

                mini -= 1;
                maxi += 1;

            }

            mini = max(0, mini);
        }

        return mini == 0;
    }
};
