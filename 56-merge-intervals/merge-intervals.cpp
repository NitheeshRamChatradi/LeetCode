class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(auto i=1;i<intervals.size();i++)
        {
            int st=intervals[i][0];
            int end=intervals[i][1];
            if(ans.back()[1]>=st)
            {
                ans.back()[1]=max(ans.back()[1],end);
                ans.back()[0]=min(ans.back()[0],st);
            }
            else
            {
                ans.push_back({st,end});
            }
        }
        return ans;
    }
};