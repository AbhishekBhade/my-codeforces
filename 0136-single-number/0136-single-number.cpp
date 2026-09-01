class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        return ans;
    }
};
// x^ x=0;
// x^ 0=x;