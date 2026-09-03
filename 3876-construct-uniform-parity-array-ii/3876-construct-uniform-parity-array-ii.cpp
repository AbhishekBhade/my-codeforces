class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int me=INT_MAX;
        int mo=INT_MAX;
        int num=0;
        bool even=false;
        bool odd=false;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even=true;
                me=min(me,nums[i]);
            }
            else{
                odd=true;
                mo=min(mo,nums[i]);
                num++;
            }
        }
        if(mo==INT_MAX) return true;
        if(me<mo) return false;
        return true;
    }
};