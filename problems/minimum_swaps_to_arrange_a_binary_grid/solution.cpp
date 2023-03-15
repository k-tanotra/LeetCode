class Solution {
public:
    void print(vector<int> &v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    int minSwaps(vector<vector<int>>& grid) {

        vector<int> z(grid.size(),0);

        for(int i=0;i<grid.size();i++){
            int count = 0;
            for(int j=grid.size()-1;j>=0;j--){
                if(grid[i][j])
                    break;
                count++;
            }
            z[i] = count;
        }

        //print(z);
        int swaps=0;
        int start = z.size()-1;
        for(int i=0;i<z.size();i++){
            if(z[i]>=start){
                start--;
                continue;
            }
            //cout<<"hell"<<endl;
            int j=i;
            while(j<z.size() && z[j]<start){
                j++;
            }
            if(j==z.size()){
                return -1;
            }
            int k=j;
            while(k>=0 && k!=i){
                swap(z[k],z[k-1]);
                swaps++;
                k--;
            }
            start--;
            //cout<<i<<endl;
            //cout<<swaps<<endl;
            //print(z);
        }
        return swaps;
    }
};