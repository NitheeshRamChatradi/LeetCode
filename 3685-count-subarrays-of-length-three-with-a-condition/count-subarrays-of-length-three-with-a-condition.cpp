class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if(nums.size()<3)
        return 0;
        int i=1,j=3,count=0;
        if(nums[1]==(nums[0]+nums[2])*2)
        count++;
        while(j<nums.size())
        {
            if((nums[i]+nums[j])*2==nums[i+1])
            count++;
            i++;
            j++;
        }
        return count;

    }
};