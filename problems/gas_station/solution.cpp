class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int n = gas.size();
        int start =-1;
        int running = 0;
        for(int i=0;i<n;i++){
            sum += gas[i] - cost[i];
            running += gas[i]-cost[i];
            if(running<0){
                start = -1;
                running = 0;
            }
            else if(running>=0 && start==-1){
                start = i;
            }
        }
        if(sum<0)
            return -1;

        return start;
        
    }
};

/*
1 2 3 4 5 
3 4 5 1 2

-2 -2 -2 3 3 

2 3 4
3 4 3
-1 -1 1
*/