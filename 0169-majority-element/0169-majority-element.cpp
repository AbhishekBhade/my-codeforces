class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int freq=0;
        unordered_map<int ,int>map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            if(map[nums[i]]>freq){
                freq=map[nums[i]];
                ans=nums[i];
            }
        }
        return ans;
    }
};