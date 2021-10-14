class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        int col = matrix[0].size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[mid][col] < target){
                low = mid + 1;
            }
            else if(matrix[mid][col] >= target){
                high = mid - 1;
            }
        }
        if(low==matrix.size()){
            return false;
        }
        int row = low;
        low = 0;
        high = matrix[0].size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[row][mid]<target){
                low = mid + 1;
            }
            else if(matrix[row][mid]>target){
                high =  mid - 1;
            }
            else{
                return true;
            } 
        }
        
        return false;
    }
};