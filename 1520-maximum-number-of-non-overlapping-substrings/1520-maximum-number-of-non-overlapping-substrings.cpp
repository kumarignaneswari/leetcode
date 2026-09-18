class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string>b;
        int n=s.size();
        vector<string>dp(n+1);
        vector<int>l(26,-1),r(26,-1);
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            if(l[c]==-1)l[c]=i;
            r[c]=i;
        }
        vector<pair<int,int>>c;
        for(int i=0;i<26;i++){
            if(l[i]==-1)continue;
            int L=l[i],R=r[i];
            bool flag=true;
            for(int j=L;j<=R;j++){
                int c=s[j]-'a';
                if(l[c]<L){
                    flag=false;
                    break;
                }
                R=max(R,r[c]);
            }
            if(flag)c.push_back({R,L});
        }
    
    sort(c.begin(),c.end());
    int e=-1;
    for(auto i:c){
        int R=i.first;
        int L=i.second;
        if(L>e){
            b.push_back(s.substr(L,R-L+1));
            e=R;
        }
    }
    return b;

    }
};