class Solution {
public:
    vector<vector<int>> transform(vector<string> &logs){
        vector<vector<int>> ans;
        for(string t:logs){
            string temp = "";
            int x = 0;
            vector<int> res;
            for(char c: t){
                if(c==':'){
                    if(temp[0]>='0' && temp[0]<='9'){
                        x=stoi(temp);
                    }
                    else if(temp=="start"){
                        x = 1;
                    }
                    else{
                        x = -1;
                    }
                    temp ="";
                    res.push_back(x);
                }
                else{
                    temp += c;
                }
            }
            x = stoi(temp);
            res.push_back(x);
            ans.push_back(res);
        }
        return ans;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<vector<int>> newLogs = transform(logs);
        /*
        for(int i=0;i<newLogs.size();i++){
            cout<<newLogs[i][0]<<" "<<newLogs[i][1]<<" "<<newLogs[i][2]<<endl;
        }
        */
        int curStart = 0;
        vector<int> ans(n,0);
        for(int i=0;i<newLogs.size();i++){
            if(st.empty()){
                st.push(newLogs[i][0]);
                curStart = newLogs[i][2];
                if(newLogs[i][1]==-1)
                    curStart++;
            }
            else{
                if(newLogs[i][1]==1){
                    ans[st.top()]+= newLogs[i][2] - curStart;
                    st.push(newLogs[i][0]);
                    curStart = newLogs[i][2];
                }
                else{
                    ans[st.top()] += newLogs[i][2]+1-curStart;
                    st.pop();
                    curStart = newLogs[i][2]+1;
                }
            }
        }
        return ans;
    }
};