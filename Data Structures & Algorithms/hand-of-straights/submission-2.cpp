class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int, int> mpp;
        for(int i = 0; i < hand.size(); i++) {
            mpp[hand[i]]++;
        }

        for(int num: hand) {
            int start = num;
            while(mpp[start - 1] > 0) start--;
            while(start <= num) {
                while(mpp[start] > 0) {
                    for(int i = start; i < start + groupSize; i++) {
                        if(mpp[i] == 0) return false;
                        mpp[i]--;
                    }
                }
                start++;
            }
        }

        return true;
    }
};
