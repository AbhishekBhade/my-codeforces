class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int p=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                p--;
            }
        }
        if(nums[0]<nums[n-1])p--;
        return p<0 ? false : true ;
    }
};