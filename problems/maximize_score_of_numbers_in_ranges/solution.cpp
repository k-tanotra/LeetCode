class Solution {
public:
    bool check(vector<int> &v,int d,int mid){
        long long last = v[0];
        for(int i=1;i<v.size();i++){
            if(last+mid>v[i]+d){
                return false;
            }
            last = max<long long int>(last+mid,v[i]);
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        long long begin = 0;
        long long end = start.back() + d;
        int res = 0;
        while(begin<=end){
            long long mid = (end-begin)/2 + begin;
             //cout<<mid<<" "<<begin<<" "<<end<<" "<<res<<endl;
            if(check(start,d,mid)){
                res = mid;
                begin = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return res;
    }
};