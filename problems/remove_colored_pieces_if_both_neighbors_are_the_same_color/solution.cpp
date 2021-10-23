class Solution {
public:
    // bool canAliceRemove(string s,int idx){
    //     if(idx==0 || idx==s.length()-1){
    //         return false;
    //     }
    //     else if(s[idx-1]=='A' && s[idx+1]=='A' && s[idx]=='A'){
    //         return true;
    //     }
    //     return false;
    // }
    // bool canBobRemove(string s,int idx){
    //     if(idx==0 || idx==s.length()-1){
    //         return false;
    //     }
    //     else if(s[idx-1]=='B' && s[idx+1]=='B' && s[idx]=='B'){
    //         return true;
    //     }
    //     return false;
    // }
    bool winnerOfGame(string colors) {
        int b = 0;
        int a = 0;
        
        if(colors.length()<=2){
            return false;
        }
        
        for(int i=1;i<colors.length()-1;i++){
            
            if(colors[i-1]=='A' && colors[i+1]=='A' && colors[i]=='A'){
                a++;
            }
            else if(colors[i-1]=='B' && colors[i+1]=='B' && colors[i]=='B'){
                b++;
            }
        }
        
        return (a>b);
    }
};