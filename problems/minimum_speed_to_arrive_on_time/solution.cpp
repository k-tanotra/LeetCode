class Solution {
public:
    double cal(int x,vector<int>& dist){
        double hours = 0;
        for(int i=0;i<dist.size();i++){
            if(i!=dist.size()-1){
                hours += ceil(1.00*dist[i]/x);
            }
            else{
                hours += (1.00*dist[i])/x;
            }
        }
        return hours;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int end = 10000000;
        int start = 1;
        double ans;
        //cout<<cal(3,dist)<<endl;
        while(start<=end){
            int mid = (end-start)/2 + start;
            ans = cal(mid,dist);
            if(ans<=hour){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        if(start>10000000)
            return -1;
        return start;
    }
};