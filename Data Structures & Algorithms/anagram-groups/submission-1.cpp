class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(auto s: strs) {
            vector<int> count(26, 0);
            for(char ch: s) {
                count[ch - 'a']++;
            }

            string key = to_string(count[0]);
            for(int i = 1; i < 26; i++) {
                key += '*' + to_string(count[i]);
            }

            res[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto pair: res) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};
