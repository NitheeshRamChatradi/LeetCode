class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> minno(m,1e5);
        vector<int> maxno(n,-1);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                minno[i]=min(minno[i],matrix[i][j]);
                maxno[j]=max(maxno[j],matrix[i][j]);
            }
        }
        vector<int> luckyNumbers;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == minno[i] && matrix[i][j] == maxno[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;

    }
};