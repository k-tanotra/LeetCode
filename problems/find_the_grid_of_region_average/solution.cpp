class Solution {
public:
    map<int,int> m;
    bool isValid(int x, int y,int R,int C){
        if(x<0 || y<0 || x>=R || y>=C){
            return false;
        }
        return true;
    }
    bool isRegion(int r,int c,vector<vector<int>>& image,int threshold){
        int R = image.size();
        int C = image[0].size();
       // cout<<"HELLO. "<<r<<" "<<c<<endl;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                //cout<<image[i][j]<<endl;
                if(isValid(i-1,j,R,C) && i-1>=r){
                    if(abs(image[i][j]-image[i-1][j])>threshold){
                        //cout<<"HELLO "<<i<<" "<<j<<endl;
                        return false;
                    }
                }
                if(isValid(i+1,j,R,C) && i+1<r+3){
                    if(abs(image[i][j]-image[i+1][j])>threshold){
                         //cout<<"HELLO "<<i<<" "<<j<<endl;
                        return false;
                    }
                }
                if(isValid(i,j-1,R,C) && j-1>=c){
                    if(abs(image[i][j]-image[i][j-1])>threshold){
                         //cout<<"HELLO "<<i<<" "<<j<<endl;
                        return false;
                    }
                }
                if(isValid(i,j+1,R,C) && j+1<c+3){
                    if(abs(image[i][j]-image[i][j+1])>threshold){
                         //cout<<"HELLO "<<i<<" "<<j<<endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    int average(int r,int c,vector<vector<int>>& image){
        int sum = 0;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
               sum += image[i][j];
            }
        }
        sum = sum/9;
        return sum;
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int ROW = image.size();
        int COL = image[0].size();
        vector<vector<pair<int,int>>> res(ROW,vector<pair<int,int>>(COL,{0,0}));
        for(int i=0;i<=ROW-3;i++){
            for(int j=0;j<=COL-3;j++){
                if(isRegion(i,j,image,threshold)){
                    //cout<<i<<" "<<j<<endl;
                    int avg = average(i,j,image);
                    for(int x=i;x<i+3;x++){
                        for(int y=j;y<j+3;y++){
                            res[x][y].first = res[x][y].first + avg;
                            res[x][y].second = res[x][y].second+1;
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans = image;
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[0].size();j++){
                if(res[i][j].second!=0){
                    ans[i][j] = res[i][j].first / res[i][j].second;
                }
            }
        }
        return ans;
    }
};