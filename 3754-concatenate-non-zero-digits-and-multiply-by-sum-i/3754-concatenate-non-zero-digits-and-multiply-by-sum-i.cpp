class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>d;
        if(n==0)return 0;
        int temp=n;
        while(temp>0){
            int b=temp%10;
            if(b>0){
                d.push_back(b);
            }
            temp=temp/10;
        }
        if(d.size()==0)return 0;
        reverse(d.begin(),d.end());
        int k=d.size();
        long long digit=0;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=d[i];
            digit=digit*10+d[i];
        }
        return digit*sum;
    }
};