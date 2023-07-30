class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int rows = matrix.size();
        int col = matrix[0].size();
        int r = 0;
        int l = col-1;
        int d = 0;
        int u = rows-1;
        
        vector<int> ans;
        while(d<=u){
            int cr = r;
            if(cr>l){
                break;
            }
            while(cr<=l){
                ans.push_back(matrix[d][cr]);
                cr++;
            }
            int cd = d;
            cd++;
            if(cd>u){
                break;
            }
            while(cd<=u){
                ans.push_back(matrix[cd][l]);
                cd++;
            }
            
            int cl = l;
            cl--;
            if(cl<r){
                break;
            }
            while(cl>=r){
                ans.push_back(matrix[u][cl]);
                cl--;
            }
            
            int cu = u;
            cu--;
            if(cu<=d){
                break;
            }
            while(cu>d){
                ans.push_back(matrix[cu][r]);
                cu--;
            }
            
            r++;
            u--;
            d++;
            l--;
        }
        
        return ans;
    }   
};