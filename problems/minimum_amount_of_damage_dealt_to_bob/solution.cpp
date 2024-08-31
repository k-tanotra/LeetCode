class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        long long totalDamage = 0;
        long long dmg = 0;
        vector<pair<long double, int>> enemies;
        for (int i = 0; i < n; ++i) {
            enemies.push_back({1.0*damage[i]/((health[i] + power - 1) / power),i});
            dmg += damage[i];
        }
        sort(enemies.rbegin(), enemies.rend());
        //cout<<enemies[0].second<<endl;
        long long currentTime = 0;
        for (const auto& enemy : enemies) {
            int enemyDamage = damage[enemy.second];
            int enemyHealth = health[enemy.second];
            int timeToKill = (enemyHealth/power);
            if(enemyHealth%power!=0){
                timeToKill += 1;
            }
            totalDamage +=  timeToKill*dmg; //25 
            dmg-=enemyDamage;
        }
        return totalDamage;
    }
};