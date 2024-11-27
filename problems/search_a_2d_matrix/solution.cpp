class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(matrix[mid][0]<= target){
                start = mid+1;
            }
            else{
                end = end-1;
            }
        }
        cout<<end<<endl;
        if(end<=-1){
            return false;
        }
        int idx = end;
        start =0;
        end = matrix[idx].size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            cout<<mid<<endl;
            if(matrix[idx][mid]==target){
                return true;
            }
            else if(matrix[idx][mid]<target){
                start = mid +1;
            }
            else{
                end = end-1;
            }
        }
        return false;
    }
};