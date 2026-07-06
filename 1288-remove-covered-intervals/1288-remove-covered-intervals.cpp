class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& pog) {
        int n=pog.size();
        sort(pog.begin(),pog.end(),[](auto& a,auto& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int cnt=0;
        int ans=n;
        for(int i=0;i<n;i++){
            if(pog[i][1]<=cnt){
                ans--;
            }
            else{
                cnt=pog[i][1];
            }
        }
        return ans;
    }
};