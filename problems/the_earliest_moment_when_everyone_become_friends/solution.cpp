class Solution {
public:
    int parent(vector<int> v,int val){
        while(val!=v[val]){
            val = v[val];
        }
        return val;
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        vector<int> vec(n,0);
        unordered_map<int,vector<int>> m;
        for(int i=0;i<vec.size();i++){
            vec[i] = i;
            vector<int> temp;
            temp.push_back(i);
            m[i] = temp;
        }
        for(int i=0;i<logs.size();i++){
            //find parent of 1;
           int p1 = parent(vec,logs[i][1]);
           int p2 = parent(vec,logs[i][2]);
           
            if(p1!=p2){
                if(p1<p2){
                    m[p1].insert(m[p1].end(), m[p2].begin(), m[p2].end()); 
                    vec[p2] = p1;
                    if(m[p1].size()==n){
                       return logs[i][0];
                    }
                }
                else{
                    m[p2].insert(m[p2].end(), m[p1].begin(), m[p1].end()); 
                    vec[p1] = p2;
                    if(m[p2].size()==n){
                        return logs[i][0];
                    }
                }
                
            }
        }
        /*
        for(int i=0;i<vec.size();i++){
           cout<<i<<" "<<vec[i]<<endl;
        }
        cout<<endl;
        for(auto itr=m.begin();itr!=m.end();itr++){
            cout<<itr->first<<" -->";
            for(int i=0;i<itr->second.size();i++){
                cout<<itr->second[i]<<" ";
            }
            cout<<" -- "<<itr->second.size();
            cout<<endl;
        }
        */
        return -1;
    }
};