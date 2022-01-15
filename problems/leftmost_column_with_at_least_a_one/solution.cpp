/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int m = dim[0];
        int n = dim[1];
        int col = n-1;
        int row = 0;
        while(row<m && col>=0){
            if(binaryMatrix.get(row,col)){
                col--;
            }
            else{
                row++;
            }
        }
        return col==n-1 ? -1 : col+1;
    }
};