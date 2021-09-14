class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int end = true;
        int ans = 0;
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        
//         while(end){
            
//             if(v[0]>0){
//                 v[0]--;
//                 v[2]--;
//             }
//             else if(v[1]>0){
//                 v[1]--;
//                 v[2]--;
//             }
//             else{
//                 break;
//             }
//             sort(v.begin(),v.end());
//             ans = ans+1;
//         }
        
        if( v[0]>= v[2]-v[1]){
            return (v[0] + v[1] + v[2])/2;
        }
        else{
            return v[0] + v[1];
        }
        return ans;
    }
};