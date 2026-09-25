class Solution {
public:
    vector<string> braceExpansionII(string expression) {
      queue<string>q;
      unordered_set<string>seen;
      set<string>res;
      q.push(expression);
      seen.insert(expression);
      while(!q.empty()){
        string cur=q.front();
        q.pop();
        int right=cur.find('}');
        if(right==string::npos){
            res.insert(cur);
            continue;
        }
        int left=cur.rfind('{',right);

        string pref=cur.substr(0,left);
        string suff=cur.substr(right+1);
        string s=cur.substr(left+1,right-left-1);
        stringstream ss(s);
        string exp;
        while(getline(ss,exp,',')){
            string next=pref+exp+suff;
            if(!seen.count(next)){
                seen.insert(next);
                q.push(next);
            }
        }
      }
      return vector<string>(res.begin(),res.end());
    }  
};