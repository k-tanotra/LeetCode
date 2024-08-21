class Solution {
public:
    string getSmallestString(string s) {
       for(int i=0;i<s.size()-1;i++){
           int x = s[i]-'0';
           int y = s[i+1] - '0';
           if(x%2==0 && y%2==0){
               if(y<x){
                   char c = s[i];
                   s[i] = s[i+1];
                   s[i+1] = c;
                   break;
               }
           }
           else if(x%2==1 && y%2==1){
               if(y<x){
                   char c = s[i];
                   s[i] = s[i+1];
                   s[i+1] = c;
                   break;
               }
           }
       }
       return s;
    }
};