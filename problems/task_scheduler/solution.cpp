class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0)
                pq.push({0,freq[i],i});
        }
        
        int curTime = 0;
        while(!pq.empty()){
            vector<int> x = pq.top();
            pq.pop();
            if(curTime<x[0]){
                curTime += x[0]-curTime +1;
            }
            else{
                curTime+=1;
            }
            cout<<curTime<<endl;
            x[1]-=1;
            if(x[1]>0){
                x[0]+=n+1;
                pq.push(x);
            }
        }
        return curTime;
        */
        vector<int> freq(26,0);
        int maxCount = 0;
        int len = tasks.size();
        for(int i=0;i<len;i++){
            freq[tasks[i]-'A']++;
            maxCount = max(maxCount,freq[tasks[i]-'A']);
        }
        
        int lastTime = (maxCount-1)*(n+1);
        for(int i=0;i<freq.size();i++){
           // cout<<freq[i]<<" "<<char(i+'A')<<endl;
            if(freq[i]==maxCount){
                lastTime++;
            }
        }
        return max(lastTime,len);
    }
};