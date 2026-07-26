class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        map<char, int> firstOccurence, lastOccurence;

        for(int i = 0; i < n; i++) {
            if(firstOccurence.find(s[i]) == firstOccurence.end()) {
                firstOccurence[s[i]] = i;
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            if(lastOccurence.find(s[i]) == lastOccurence.end()) {
                lastOccurence[s[i]] = i;
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int last = lastOccurence[s[i]];

            int j = i + 1;
            while(j < last) {
                last = max(last, lastOccurence[s[j]]);;
                j++;
            }
            ans.push_back(last - i + 1);
            i = last;
        }

        return ans;
    }
};
