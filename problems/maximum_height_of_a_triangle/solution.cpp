class Solution {
public:
    int solve(int red,int blue,bool type){
        int start = 1;
        int toggle=type;
        int height = 0;
        while(red>=0 && blue>=0){
            if(toggle){
                blue -= start;
                if(blue<0){
                    break;
                }
                
            }
            else{
                red -= start;
                if(red<0){
                    break;
                }
            }
            start++;
            height++;
            toggle = !toggle;
        }
        return height;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red,blue,false),solve(red,blue,true));
    }
};