class Solution {
public:
    int extract(string s){
        int i = 0;
        while(s[i]!='\0'){
            if(s[i]!='.'){
                i++;
            }
            else{
                break;
            }
        }
        
        return i+4;
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int len = paths.size();
        map<string,vector<string>> m;
        
        vector<vector<string>> ans;
        
        for(int i=0;i<len;i++){
            string s = paths[i];
            string temp = "";
            string path = "";
            int j =0;
            while(s[j]!='\0'){
                if((s[j]==' ') || (s[j+1]=='\0')){
                    if(path.empty()){
                        path = temp;
                        temp = "";
                        j++;
                        continue;
                    }
                    else{
                        int index = extract(temp);
                        string p1 = temp.substr(0,index);
                        string p2 = temp.substr(index);
                        if(s[j+1]=='\0'){
                            p2 = p2 + ')';
                        }
                        
                        // cout<<p1<<" "<<p2<<endl;
                        if(m.find(p2)==m.end()){
                            vector<string> v;
                            p1 = path + '/' + p1;
                            v.push_back(p1);
                            m.insert({p2,v});
                        }
                        else{
                            p1 = path + '/' + p1;
                            m[p2].push_back(p1);
                        }
                        temp = "";
                        j++;
                        continue;
                    }
                }
                temp = temp + s[j];
                j++;
            }
        }
        
        for(auto itr=m.begin();itr!=m.end();itr++){
            // cout<<itr->first<<" ";
            if(itr->second.size()>1){
                ans.push_back(itr->second);
            }
        }
        
        return ans;
    }
};