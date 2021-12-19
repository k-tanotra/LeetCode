class Solution {
public:
    unordered_map<int,int> m;
    int dfs(long n){
        if(n<=1){
            return 0;
        }
        if(m.find(n)!=m.end()){
            return m[n];
        }
        if(n%2==0){
            m[n] = 1+dfs(n/2);
        }
        else{
            m[n] = 1+min(dfs(n+1),dfs(n-1));         
        }
        return m[n];
    }
    int integerReplacement(int n) {
        /*
         for(auto itr=m.begin();itr!=m.end();itr++){
            cout<<itr->first<<" "<<itr->second<<endl;
        }
        */
        return  dfs(n);
    }
};