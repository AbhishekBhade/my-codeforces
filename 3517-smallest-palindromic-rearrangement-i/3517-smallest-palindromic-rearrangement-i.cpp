class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        char mid=s[n/2];
        string ans="";
        for(int i=0;i<n/2;i++){
            ans.push_back(s[i]);
        }
        sort(ans.begin(),ans.end());
        string rev=ans;
        reverse(rev.begin(),rev.end());
        if(n%2==1){
            return ans+mid+rev;
        }
        else{
            return ans+rev;
        }
    }
};