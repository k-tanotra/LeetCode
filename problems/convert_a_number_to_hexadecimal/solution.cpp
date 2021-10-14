class Solution {
public:
    string mapping(int num){
        if(num<10)
            return to_string(num);
        
        switch(num){
            case 10:
                return "a";
            case 11:
                return "b";
            case 12:
                return "c";
            case 13:
                return "d";
            case 14:
                return "e";
            case 15:
                return "f";  
        }
        
        return "";
    }
    
    string removeZeros(string s){
        int i=0;
        string ans;
        while(s[i]!='\0'){
            if(s[i]=='0'){
                i++;
            }
            else{
                break;
            }
        }
        return s.substr(i);
    }
    string toHex(int num) {
       string ans = "";
       if(num==0){
           return "0";
       }
       bool found=false;
       for(long i=1;i< pow(2,31)-1;i=i*16){
           int n = 0;
           if((num & i)!=0){
               n+= 1;
           }
           if((num & i*2)!=0){
               n+= 2;
           }
           if((num & i*4)!=0){
               n+= 4;
           }
           if((num & i*8)!=0){
               n+= 8;
           }
           ans = mapping(n) + ans;
       }
       ans = removeZeros(ans);
       return ans;
    }
};