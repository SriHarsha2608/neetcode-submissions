class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool possibleX = false, possibleY = false, possibleZ = false;

        int n = triplets.size();
        for(int i = 0; i < n; i++) {
            if(triplets[i][0] == target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                possibleX = true;
            }

            if(triplets[i][0] <= target[0] && triplets[i][1] == target[1] && triplets[i][2] <= target[2]) {
                possibleY = true;
            }

            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] == target[2]) {
                possibleZ = true;
            }
        }
        // for(int i = 0; i < n; i++) {
            
        // }
        // for(int i = 0; i < n; i++) {
            
        // }


        return possibleX && possibleY && possibleZ;
    }
};
