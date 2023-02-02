class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans = "";
        int start = 0;
        int end = s.size()-1;
        while(s[start]==' '){
            start++;
        }
        while(s[end]==' '){
            end--;
        }
        for(int i=end;i>=start-1;i--){
            if(i==-1 || s[i]==' '){
                bool in = false;
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                    in = true;
                }
                if(i!=start-1 && in ==true){
                    ans+=s[i];
                }
            }
            else{
                st.push(s[i]);
            }
        }
        return ans;
    }
};