class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        int sum1=0,sum2=0;
        for(auto i:s1) sum1+=i;
		for(auto i:s2) sum2+=i;
        for(int i=1;i<=s1.size();i++)
        {
            for(int j=1;j<=s2.size();j++)
            {
                if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+s1[i-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ans=dp[s1.size()][s2.size()];
        // int i=s1.size(),j=s2.size();
        // while(i>0 && j>0)
        // {
        //     if(s1[i-1]==s2[j-1])
        //     {
        //         i--;
        //         j--;
        //     }
        //     else if(dp[i-1][j]>dp[i][j-1])
        //     {
        //         i--;
        //         ans+=s1[i];
        //         cout<<s1[i];
        //     }
        //     else if(dp[i-1][j]<dp[i][j-1])
        //     {
        //         j--;
        //         ans+=s2[j];
        //         cout<<s2[j];
        //     }
        //     else 
        //     {
        //         if(s1[i-1]>s2[j-1])
        //         {
        //             j--;
        //         ans+=s2[j];
        //         cout<<s2[j];
        //         }
        //         else
        //         {
        //             i--;
        //         ans+=s1[i];
        //         cout<<s1[i];
        //         }
        //     }
        // }
        // while(i>0)
        // {
        //     ans+=s1[i-1];
        //     i--;
        //     cout<<s1[i];
        // }
        // while(j>0)
        // {
        //     ans+=s2[j-1];
        //     j--;
        //     cout<<s2[j];
        // }
        return sum1+sum2-2*ans;
    }
};