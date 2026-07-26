class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;

        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R') {
                r.push(i);
            } else {
                d.push(i);
            }
        }

        while(!r.empty() && !d.empty()) {
            int rIndex = r.front();
            r.pop();
            int dIndex = d.front();
            d.pop();

            if(rIndex < dIndex) {
                r.push(rIndex + n);
            } else {
                d.push(dIndex + n);
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};