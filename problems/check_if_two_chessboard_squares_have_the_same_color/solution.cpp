class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int x1 = coordinate1[0]-'a';
        int y1 = coordinate1[1]-'0';
        int x2 = coordinate2[0]-'a';
        int y2 = coordinate2[1]-'0';
        int white1 = 0;
        int white2 = 0;
        if(((x1+1)%2!=0 && (y1%2==0)) || ((x1+1)%2==0 && (y1%2!=0))){
            white1 = 1;
        }
        if(((x2+1)%2!=0 && (y2%2==0)) || ((x2+1)%2==0 && (y2%2!=0))){
            white2 = 1;
        }
        if(white1==white2){
            return true;
        }
        return false;
    }
};