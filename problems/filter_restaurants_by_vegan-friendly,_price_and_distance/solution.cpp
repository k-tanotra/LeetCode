class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[1]==b[1])
            return a[0]>b[0];
        return a[1]>b[1];
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        sort(restaurants.begin(),restaurants.end(),cmp);
        vector<int> res;
        for(int i=0;i<restaurants.size();i++){
            //cout<<restaurants[i][0]<<endl;
            if( ( !veganFriendly || restaurants[i][2]==veganFriendly) && restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance){
                res.push_back(restaurants[i][0]);
            }
        }
        return res;
    }
};