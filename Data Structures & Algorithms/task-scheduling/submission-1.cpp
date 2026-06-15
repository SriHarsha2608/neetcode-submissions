class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char task: tasks)
        {
            freq[task - 'A']++;
        }
        set<pair<int,char>>unlocked_tasks;
        for(int i=0;i<26;i++){
        if(freq[i]>0)
            unlocked_tasks.insert({freq[i],char('A'+i)});
        }
        int currTime = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>minPq;
        while(!minPq.empty() || !unlocked_tasks.empty()){
            while(!minPq.empty() && minPq.top().first<=currTime){
                auto [freq,c]= minPq.top().second;minPq.pop();
                unlocked_tasks.insert({freq,c});
            }
            currTime++;
            if(unlocked_tasks.empty())continue;
            auto [freq_now,c_now] = *prev(unlocked_tasks.end());
            unlocked_tasks.erase(prev(unlocked_tasks.end()));
            if(freq_now>1)minPq.push({currTime+n,{freq_now-1,c_now}}); 
        }
        return currTime;
    }
};
