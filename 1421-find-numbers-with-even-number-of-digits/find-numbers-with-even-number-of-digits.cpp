class Solution {
public:
    int no_of_digits(int n)
    {
        int count=0;
        while(n>0)
        {
            n=n/10;
            count++;
        }
        return count;
    }

    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int &i:nums)
        {
            if(no_of_digits(i)%2==0)
            ans++;
        }
        return ans;
        
    }
};