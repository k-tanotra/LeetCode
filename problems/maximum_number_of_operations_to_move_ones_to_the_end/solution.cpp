class Solution {
public:
    int maxOperations(string s) {
       int n = s.size();
       int ones = 0;
       int moves = 0;
       for(int i=0;i<n-1;){
           if(s[i]=='0'){
               ones = 0;
           }
           if(s[i]=='1'){
               ones++;
           }
           if(s[i]=='1' && s[i+1]=='0'){
               while(i+1<n && s[i+1]=='0'){
                   i++;
               }
               moves+=ones;
               if(i+1==n){
                   return moves;
               }
           }
           i++;
       }
      return moves;
    }
};