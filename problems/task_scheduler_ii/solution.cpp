class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long> m;
        long long days = 1;
        for(int i=0;i<tasks.size();i++){
            if(m.find(tasks[i])==m.end()){
                m.insert({tasks[i],days+space+1});
                days++;
            }
            else{
                if(days<=m[tasks[i]]){
                    days = m[tasks[i]];
                    m[tasks[i]] = days+space+1;
                    days++;
                }
                else{
                    m[tasks[i]] = days+space+1;
                    days++;
                }
            }
        }
        return days-1;
    }
};