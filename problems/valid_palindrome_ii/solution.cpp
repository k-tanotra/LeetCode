class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        int c =0;
        while(start<=end){
            //cout<<start<<" "<<end<<endl;
            if(s[start]!=s[end]){
                c++;
                int stemp = start;
                int etemp = end;
                stemp++;
                while(stemp<=etemp && s[stemp]==s[etemp]){
                    stemp++;
                    etemp--;
                }
                if(stemp>etemp){
                    return true;
                }
                //cout<<start<<" "<<end<<endl;
                
                stemp = start;
                etemp = end;
                etemp--;
                //cout<<start<<" "<<end<<endl;
                while(stemp<=etemp && s[stemp]==s[etemp]){
                    
                    stemp++;
                    etemp--;
                }
                if(stemp>etemp){
                    return true;
                }
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        
        return true;
    }
};