class Solution {
public:
    void print(vector<int> arr){
        for(int num:arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    int parent(vector<int> arr,int i){
        while(arr[i]!=i){
            i = arr[i];
        }
        return i;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = i;
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]){
                    int x = parent(arr,j);
                    int y = parent(arr,i);
                    arr[x] = y;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==arr[i]){
                ans++;
            }
        }
        return ans;
    }
};