class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string common = strs[0];
        for(int i=1;i<n;i++){
            int l1 = common.size();
            int l2 = strs[i].size();
            int j = 0;
            string s = "";
            while(j<l1 && j<l2){
                if(common[j]==strs[i][j]){
                    s += common[j];
                }
                else{
                    break;
                }
                j++;
            }
            //cout<<common<<endl;
            common = s;
            if(common=="")
                break;
        }
        return common;
    }
};