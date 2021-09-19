class Solution {
public:
    string countAndSay(int n) {
        
        int count = 1;
        if(n==1){
            return "1";
        }
        string ans = "1$";
        for(int i=2;i<=n;i++){
            string temp = "";
            for(int j=0;j<ans.length()-1;j++){
                if(ans[j]==ans[j+1]){
                    count++;
                }
                else{
                    char c = '0' + count;
                    // cout<<c<<"--"<<ans[j]<<endl;
                    temp += c;
                    temp += ans[j];
                    // cout<<temp<<endl;
                    count = 1;
                }
                // cout<<temp<<endl;
            }
            ans = temp;
            ans += '$';
        }
        
        return ans.substr(0, ans.size()-1);;
    }
};