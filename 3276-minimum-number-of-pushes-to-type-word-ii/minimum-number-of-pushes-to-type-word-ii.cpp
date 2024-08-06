class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        for(auto ch:word)
        {
            mp[ch]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        int ans=0;
        int count=0;
        while(!pq.empty())
        {
            auto [freq,ch]=pq.top();
            pq.pop();
            count++;
            int n=count/8+(count%8==0?0:1);
            ans+=(freq*(n));
            //cout<<ceil(count/8)<<" "; 
        }
        return ans;
    }
};