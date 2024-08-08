class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ansv;
        int i=rStart,j=cStart;
        int count=1;
        ansv.push_back({i,j});
        while(ansv.size()!=(rows*cols))
        {
            for(int k=1;k<=count;k++)
            {
                j++;
                if(i>=0 && i<rows && j>=0 && j<cols)
                ansv.push_back({i,j});
            }
            for(int k=1;k<=count;k++)
            {
                i++;
                if(i>=0 && i<rows && j>=0 && j<cols)
                ansv.push_back({i,j});
            }
            count++;
            for(int k=1;k<=count;k++)
            {
                j--;
                if(i>=0 && i<rows && j>=0 && j<cols)
                ansv.push_back({i,j});
            }
            for(int k=1;k<=count;k++)
            {
                i--;
                if(i>=0 && i<rows && j>=0 && j<cols)
                ansv.push_back({i,j});
            }
            count++;
        }
        return ansv;
    }
};