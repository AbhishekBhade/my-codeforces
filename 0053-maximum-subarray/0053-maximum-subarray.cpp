class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int ans=0;
        int f=INT_MIN;
        int i=0;
        while(i<n){
            ans+=nums[i];
            f=max(f,ans);
            if(ans<0){
                ans=0;
            }
            i++;
        }
        return f;
    }
};