class Solution {
public:
    static bool cmp(string s1,string s2){
        int i=0;
        while(s1[i]!='\0' && s1[i]!=' '){
            i++;
        }
        int x = i;
        i=0;
        while(s2[i]!='\0' && s2[i]!=' '){
            i++;
        }
        int y = i;
        if(s1.substr(x) == s2.substr(y)){
            return s1 < s2;
        }
        return s1.substr(x) < s2.substr(y);
    }
    int find(string s,char c){
        int i=0;
        while(s[i]!='\0' && s[i]!=c){
            i++;
        }
        return i;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> strs;
        vector<string> digi;
        
        int len = logs.size();
        
        string s;
        string id;
        int sindex;
        for(int i=0;i<len;i++){
            sindex = find(logs[i],' ');
            
            if(logs[i][sindex+1]>='0' && logs[i][sindex+1]<='9'){
                digi.push_back(logs[i]);
            }
            else{
                // s = logs[i].substr(sindex+1);
                // id = logs[i].substr(0,sindex);
                // s = s+'$'+id;
                strs.push_back(logs[i]);
            }
        }
        
        sort(strs.begin(),strs.end(),cmp);
        // int len2 = strs.size();
        // for(int i=0;i<len2;i++){
        //     sindex = find(strs[i],'$');
        //     id = strs[i].substr(sindex+1);
        //     s = strs[i].substr(0,sindex);
        //     s = id + ' ' + s;
        //     strs[i] = s;
        // }
        
        strs.insert(strs.end(), digi.begin(), digi.end());
        
        return strs;
    }
};