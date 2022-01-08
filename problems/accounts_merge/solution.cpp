class Solution {
public:
    int findParent(int x,vector<int> arr){
        int i = x;
        while(i!=arr[i]){
            i=arr[i];
        }
        return i;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n =  accounts.size();
        unordered_map<string,int> m;
        vector<int> arr;
        
        for(int i=0;i<n;i++){
            arr.push_back(i);
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])!=m.end()){
                    int temp = m[accounts[i][j]];
                    while(temp!=arr[temp]){
                        temp = arr[temp];
                    }
                    arr[temp] = i;
                }
                else{
                    m[accounts[i][j]] = i;
                }
            }
        }
        /*
        for(auto itr=m.begin();itr!=m.end();itr++){
            cout<<itr->first<<" "<<arr[itr->second]<<"-->"<<findParent(itr->second,arr)<<endl;
        }*/
        
        unordered_map<int,vector<string>> m2;
        for(auto itr=m.begin();itr!=m.end();itr++){
            int t = itr->second;
            while(t!=arr[t]){
                t=arr[t];
            }
            //cout<<t<<endl;
            //return i;
            if(m2.find(t)==m2.end()){
                //cout<<"hi"<<endl;
                m2.insert({t,{ accounts[itr->second][0], itr->first }});
            }
            else{
                //cout<<"bye"<<endl;
                m2[t].push_back(itr->first);
            }
        }
     
        vector<vector<string>> res;
        for(auto itr=m2.begin();itr!=m2.end();itr++){
            sort(itr->second.begin()+1,itr->second.end());
            res.push_back(itr->second);
        }
        return res;
    }
};