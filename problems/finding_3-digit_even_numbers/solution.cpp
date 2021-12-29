class Solution {
public:
    unordered_map<int,int> m;
    bool check(int num){
        unordered_map<int,int> m2;
        while(num>0){
            m2[num%10]++;
            num=num/10;
        }
        for(auto itr=m2.begin();itr!=m2.end();itr++){
            //cout<<itr->first<<" "<<itr->second<<" -- ";
            //cout<<m[itr->first]<<" ** "<<endl;
            if(m.find(itr->first)==m.end() || m[itr->first]< itr->second){
                return false;
            }
        }
        //cout<<endl;
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            if(m.find(digits[i])==m.end()){
                m.insert({digits[i],1});
            }
            else{
                m[digits[i]]++;
            }
        }
        /*
        for(auto itr=m.begin();itr!=m.end();itr++){
            cout<<itr->first<<" "<<itr->second<<" -- ";
        }
        */
        //cout<<endl;
        //cout<<" ------------ "<<endl;
        for(int i=100;i<=999;i+=2){
            if(check(i)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};