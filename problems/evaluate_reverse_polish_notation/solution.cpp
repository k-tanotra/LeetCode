class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> x;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="*" || tokens[i]=="-" || tokens[i]=="/"){
                int a = stoi(x.top());
                x.pop();
                int b = stoi(x.top());
                x.pop();
                if(tokens[i]=="+"){
                    x.push(to_string(a+b));
                }
                else if(tokens[i]=="-"){
                     x.push(to_string(b-a));
                }
                else if(tokens[i]=="*"){
                     x.push(to_string(a*b));
                }
                else if(tokens[i]=="/"){
                     x.push(to_string(b/a));
                }
            }
            else{
                x.push(tokens[i]);
            }
        }
        return stoi(x.top());
    }
};