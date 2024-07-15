class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),-1));
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0){
                q.push({{i,j},0});
                ans[i][j]=0;
                }
            }
        }
        int row[]={-1,0,0,+1};
        int col[]={0,-1,+1,0};
        while(!q.empty())
        {
            auto p=q.front();
            
            q.pop();
            int r=p.first.first,c=p.first.second;
            for(int i=0;i<4;i++)
            {
                int r1=r+row[i];
                int c1=c+col[i];
                if(r1>=0 && r1<m && c1>=0 && c1<n && ans[r1][c1]==-1)
                {
                    q.push({{r1,c1},p.second+1});
                    ans[r1][c1]=p.second+1;
                }
            }

        }
        return ans;
    }
};