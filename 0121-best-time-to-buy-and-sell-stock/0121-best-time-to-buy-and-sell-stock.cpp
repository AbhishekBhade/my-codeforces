class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        if(n<=1)return 0;
        int buy=arr[0];
        int sell=0;
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            if(arr[i]<buy){
                buy=arr[i];
            }
            int profit=arr[i]-buy;
            ans=max(ans,profit);
        }
        return ans;
    }
};