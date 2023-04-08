class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            if(s[i]=='c' && st.size()>2){
                char c = st.top();
                st.pop();
                char b = st.top();
                st.pop();
                char a = st.top();
                st.pop();
                if(!(c=='c' && b=='b' && a=='a')){
                    st.push(a);
                    st.push(b);
                    st.push(c);
                }
            }
        }

        return (st.size()==0);
    }
};