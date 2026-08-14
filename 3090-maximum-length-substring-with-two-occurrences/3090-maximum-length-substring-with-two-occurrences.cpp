class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>what;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            what[s[j]]++;
            
            if(what[s[j]]>2){
                while(what[s[j]]>2){
                    what[s[i]]--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};//i liked this i mean this is epic
