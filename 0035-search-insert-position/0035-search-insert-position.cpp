class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<=j){
            int m=i+(j-i)/2;
            if(nums[m]==t){
                return m;
            }
            else if(nums[m]>t){
                j=m-1;
            }
            else{
                i=m+1;
            }

        }
        return i;
    }
};