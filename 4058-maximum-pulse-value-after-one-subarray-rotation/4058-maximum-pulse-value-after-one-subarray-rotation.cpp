class Solution {
public:
    long long maxValue(vector<int>& nums) {
        long long cnt=0;
        long long e=0,o=-1e18,s=0,ans=1e18;
        for(int i=0;i<nums.size();i++)
        {
            s+=(i%2==0 ? nums[i]: -nums[i]);
            //even length
            if((i+1)%2==0){
                ans=min(s-e,ans);
                e=max(e,s);
            }
            else{
                ans=min(s-o,ans);
                o=max(o,s);
            }
        }
        s-=2*min(0LL,ans);
        return s;
    }
};