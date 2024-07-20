class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        vector<int> maxGap(k+1,0);
        for(int i=0;i<n/2;i++){
            int diff = abs(nums[i]-nums[n-i-1]);
            mp[diff]++;
            int gap1 = k-min(nums[i],nums[n-i-1]);
            int gap2 = max(nums[i],nums[n-i-1])-0;
            int gap = max(gap1,gap2);
            maxGap[gap]++;
        }
        for(int i=k-1;i>=0;i--){
            maxGap[i] = maxGap[i]+maxGap[i+1];
// If a differnce can be i+1 then it can also be i.
        }
        int ans = INT_MAX;
        for(auto &a: mp){
            
                int one_element_change = maxGap[a.first]-a.second;
                int two_element_change = (n/2-maxGap[a.first])*2;
                int total = one_element_change+two_element_change;
                ans = min(ans,total);
            
            
        }
        return ans;

    }
};