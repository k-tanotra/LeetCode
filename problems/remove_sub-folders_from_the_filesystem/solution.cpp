class Solution {
public:
    void print(vector<string> vec){
        for(string s:vec){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    bool check(string s1,string s2){
        
        int n = s1.length();
        int m = s2.length();
        if(m<n){
            return false;
        }
        else if(n==m && s1!=s2){
            return false;
        }
        int i=0;
        int j=0;
        while(i<n && j<m && s1[i]==s2[j]){
            i++;
            j++;
        }
        if(i<n || s2[j]!='/'){
            return false;
        }
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        //print(folder);
        vector<string> ans;
        int j=1;
        int i=0;
        string prev = folder[0];
        ans.push_back(folder[0]);
        while(j<folder.size()){
            if(check(folder[i],folder[j])){
                j++;
            }
            else{
                ans.push_back(folder[j]);
                i=j;
                j=i+1;
            }
        }
        return ans;
    }
};