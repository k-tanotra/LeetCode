class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        string num = "";
        int w = -1;
        for(int i=0;i<abbr.length();i++){
            if(abbr[i]>='0' && abbr[i]<='9'){
                num += abbr[i];
            }
            else{
               if(num.length()==0){
                   w = w+1;
                   /*if(w>=word.size()){
                       cout<<w<<endl;
                       return false;
                   }
                   */
                   if(word[w]!=abbr[i]){
                       return false;
                   }
               }
               else{
                   //cout<<"h"<<endl;
                   if(num[0]=='0'){
                       return 0;
                   }
                   int x = stoi(num)+1;
                   if(w+x>=word.size()){
                       return false;
                   }
                   else if(word[w+x]!=abbr[i]){
                       return false;
                   }
                   w=w+x;
                   num="";
               }
            }
        }
        if(num.length()!=0){
            if(num[0]=='0'){
                return false;
            }
            w = w+stoi(num);
        }
        if(w!=word.size()-1){
            return false;
        }
        return true;
    }
};