class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> rem;
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                //cout<<"hi"<<endl;
                while(!st.empty() && st.top().first==')'){
                    rem.insert(st.top().second);
                    st.pop();
                }
                st.push({'(',i});
            }
            else if(s[i]==')'){
                //cout<<"bye"<<endl;
                if(!st.empty() && st.top().first=='('){
                    //cout<<"well"<<endl;
                    st.pop();
                }
                else{
                    rem.insert(i);
                }
            }
        }
        //cout<<"well"<<endl;
        /*
        for(auto itr=rem.begin();itr!=rem.end();itr++){
            cout<<s[*itr]<<" "<<*itr<<endl;
        }
        cout<<endl;
        */
        while(!st.empty()){
            rem.insert(st.top().second);
            st.pop();
        }
        
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(rem.find(i)==rem.end()){
                ans += s[i];
            }
        }
        return ans;
    }
};