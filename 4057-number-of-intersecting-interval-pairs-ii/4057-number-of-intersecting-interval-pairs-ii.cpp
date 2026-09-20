class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<long long>start(n),end_(n);
        for(int i=0;i<n;i++){
            start[i]=intervals[i][0];
            end_[i]=intervals[i][1];
        }
        sort(start.begin(),start.end());
        sort(end_.begin(),end_.end());
        long long ans=0;
        int i=0,j=0,cnt=0;
        while(i<n){
            if(start[i]<=end_[j]){
                ans+=cnt;
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
        }
        return ans;
    }
};