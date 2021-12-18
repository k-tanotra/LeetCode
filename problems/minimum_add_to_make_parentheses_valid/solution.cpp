class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                bool flag = false;
                if(!st.empty() && st.top()=='('){
                    st.pop();
                    flag = true;
                }
                if(!flag){
                    st.push(')');
                }
            }
            else{
                st.push('(');
            }
        }
        
        return st.size();
    }
};