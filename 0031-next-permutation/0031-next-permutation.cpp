class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        int p=-1;
        while(i>0){
            if(nums[i]>nums[i-1]){
                p=i-1;
                i=n-1;
                break;
            }
            i--;
        }
        if(p==-1){
            reverse(nums.begin(),nums.end());
            return ;
        } 
        int k=0;
        while(i>p){
            if(nums[i]>nums[p]){
                k=i;
                break;
            }
            i--;
        }
        swap(nums[k],nums[p]);
        reverse(nums.begin()+p+1,nums.end());
    }
};