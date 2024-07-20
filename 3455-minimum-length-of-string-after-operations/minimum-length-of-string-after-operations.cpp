class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
        mp[s[i]]++;
        int ans=0;
        for(auto i:mp)
        {
            
            ans+=(i.second%2)?1:2;
        }
        return ans;
    }
};