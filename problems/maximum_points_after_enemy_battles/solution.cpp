class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
       // 2,2,3
        int n = enemyEnergies.size();
        sort(enemyEnergies.begin(),enemyEnergies.end());
        int start = 0;
        int end = n-1;
        long long pts = 0;
        while(start<=end){
            if(currentEnergy>=enemyEnergies[start]){
                pts += currentEnergy/enemyEnergies[start];
                currentEnergy = currentEnergy%enemyEnergies[start];
            }
            else{
                if(pts>=1)
                    currentEnergy += enemyEnergies[end];
                end--;
            }
        }
        return pts;
    }
};

//1 2 3
//0
//0