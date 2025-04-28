class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long count=0,ans=0;
        int i=0,j=0;
        while(j<nums.size())
        {
        count+=nums[j];
            if((count*(j-i+1))<k)
            {
                j++;
            }
            else
            {
                ans+=(j-i);
                count-=nums[i];
                count-=nums[j];
                i++;
            }

        }
        long n=(j-i);
        if(count*(j-i)<k)
        ans+=((n*(n+1))/2);
        return ans;

    }
};