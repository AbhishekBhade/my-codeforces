class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        //if(n<3)return -1;
        if(n==3)return nums[0]*nums[1]*nums[2];
        sort(nums.begin(),nums.end());
        int res=1;
        for(int i=n-1;i>=n-3;i--){
            res*=nums[i];
        }
        int sec=nums[0]*nums[1]*nums[n-1];
        return max(res,sec);
    }
};