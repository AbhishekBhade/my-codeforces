class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<=j){
            int k=(i+j)/2;
            if(nums[k]==target){
                return k;
            }
            else if(nums[k]>target){
                j=k-1;
            }
            else{
                i=k+1;
            }
        }
        return -1;
    }
};