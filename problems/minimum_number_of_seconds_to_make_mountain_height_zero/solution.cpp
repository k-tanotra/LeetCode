class Solution {
public:
    struct det{
        long long time;
        int original;
        int height;
    };

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        if(workerTimes.size()==1){
            return workerTimes[0]* (long long)mountainHeight*(mountainHeight+1)/2;
        }
        auto customComparator = [](det& a, det& b) {
            if(a.time==b.time){
                if(a.original==b.original){
                    a.height>b.height;
                }
                return a.original>b.original;
            }
            return a.time>b.time;
        };
        priority_queue<det,vector<det>,decltype(customComparator)> pq(customComparator);
        for(int i=0;i<workerTimes.size();i++){
            pq.push({workerTimes[i],workerTimes[i],1});
        }
        int mx = 0;
        while(!pq.empty() &&  mountainHeight>0){
            det x = pq.top();
            long long y = (x.original*(x.height +1));
            //cout<<"Time Next "<<y<<endl;
            //cout<<x.time<<" "<<x.original<<" "<<x.height<<endl;
            pq.pop();
            mx=x.time;
            mountainHeight -=1;
            pq.push({y+x.time,x.original,x.height+1});
        }
        return mx;
    }
};
// 4 1
// 10,