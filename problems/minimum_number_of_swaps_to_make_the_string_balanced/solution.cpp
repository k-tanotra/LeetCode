class Solution {
public:
    void print(stack<char> st){
        while(!st.empty()){
            cout<<st.top()<<" -- ";
            st.pop();
        }
        cout<<"\n";
    }
    int minSwaps(string s) {
       stack<char> st;
       for(int i=0;i<s.size();i++){
          if(!st.empty() && s[i]==']'){
              st.pop();
          }
          else if(s[i]=='['){
              st.push(s[i]);
          }
       }
       int ans=st.size();
       return st.size()%2==0 ? st.size()/2 : (st.size()+1)/2;
    }
};