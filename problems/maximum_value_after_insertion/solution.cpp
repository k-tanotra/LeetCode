class Solution {
public:
    string maxValue(string n, int x) {
        int i=0;
        if(n[0]!='-'){
            while(n[i]!='\0'){
                if( (n[i]-'0') < x ){
                    break;
                }
                i++;
            }
        }
        else{
            i++;
            while(n[i]!='\0'){
                if( (n[i]-'0')> x ){
                    break;
                }
                i++;
            }
        }
        
        string xs = to_string(x);
        
        // cout<<i<<" "<<n.length()<<endl;
        if(i>=n.length()){
            return n + xs;
        }
        
        n.insert(i,xs);
        return n;
    }
};