class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n - 1] == '1') return false;

        queue<int> q;
        q.push(0);
        int maxi = 0;
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            int start = max(idx + minJump, maxi + 1);
            for(int j = start; j < min(idx + maxJump + 1, n); j++) {
                if(s[j] == '0') {
                    q.push(j);
                    if(j == n - 1) {
                        return true;
                    }
                }
            }
            maxi = idx + maxJump;
        }

        return false;
    }
};