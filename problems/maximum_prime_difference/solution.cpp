class Solution {
public:
    unordered_set<int> getAllPrimes(int n){
        unordered_set<int> s;
        for(int i=2;i<=n;i++){
            bool t = true;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    t=false;
                    break;
                }
            }
            if(t)
                s.insert(i);
        }
        return s;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        unordered_set<int> s = getAllPrimes(100);
        /*for(auto itr=s.begin();itr!=s.end();itr++){
            cout<<*itr<<" ";
        }*/
        cout<<endl;
        int x;
        int y;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])!=s.end()){
                x = i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(s.find(nums[i])!=s.end()){
                y = i;
                break;
            }
        }
        return y-x;
    }
};