class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int m=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            m=max(m,nums[i]);
        }
        int i=0,j=0,count=0;
        long long ans=0;
        while(j<nums.size())
        {
            if(nums[j]==m)
                 count++;
            if(count<k){  
            j++;
            }
            else 
            {
                ans+=(nums.size()-j);
                if(nums[i]==m)
                count--;
                count--;
                i++;
            }
            
        }
        return ans;
    }
};