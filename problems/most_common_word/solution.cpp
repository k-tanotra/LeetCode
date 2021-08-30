class Solution {
public:
    char toLower(char c){
        if (c <= 'Z' && c >= 'A')
            return c - ('Z' - 'z');
       return c;
    }
    
    bool isLetter(char c){
        if(c>='A' && c<='Z'){
            return true;
        }
        else if(c>='a' && c<='z'){
            return true;
        }
        return false;
    }
    
    string getNextWord(string paragraph,int index,int* p){
         
        string ans = "";
        while(isLetter(paragraph[index])){
            ans = ans + toLower(paragraph[index]);
            index = index+1;
        }
        *p = index;
        return ans;
        
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        map<string,bool> ban;
        for(int i=0;i<banned.size();i++){
            if(ban.find(banned[i])==ban.end())
                ban.insert({banned[i],true});
        }
        
        map<string,int> freq;
        int k=0;
        int f_max = 0;
        string ans;
        string temp;
        while(paragraph[k]!='\0'){
           if(!isLetter(paragraph[k]))
               k = k + 1;
           else{
               temp = getNextWord(paragraph,k,&k);
               if(ban.find(temp)==ban.end()){
                   if(freq.find(temp)==freq.end()){
                       freq.insert({temp,1});
                   }
                   else{
                       freq[temp]++;
                   }
                   if(freq[temp]>f_max){
                       f_max = freq[temp];
                       ans = temp;
                   }
               }
           }
        }
        
        return ans;
    }
};