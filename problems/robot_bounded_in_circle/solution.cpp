class Solution {
public:
    char update(char c,char dir){
        if(dir=='N'){
            if(c=='L'){
                return 'W';
            }
            else{
                return 'E';
            }
        }
        else if(dir=='S'){
            if(c=='L'){
                return 'E';
            }
            else{
                return 'W';
            }
        }
        else if(dir=='E'){
            if(c=='L'){
                return 'N';
            }
            else{
                 return 'S';
            }
        }
        else if(dir=='W'){
            if(c=='L'){
                 return 'S';
            }
            else{
                 return 'N';
            }
        }
        return 'N';
    }
    
    void move(int* x,int* y,char dir){
        if(dir=='N'){
            *y = *y  + 1;
        }
        else if(dir=='S'){
            *y = *y  - 1;
        }
        else if(dir=='E'){
            *x = *x  + 1;
        }
        else if(dir=='W'){
            *x = *x  - 1;
        }
    }
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        char dir = 'N';
        
        int j;
        for(int i=0;i<4;i++){
            j=0;
            while(instructions[j]!='\0'){
                if(instructions[j]=='G'){
                    move(&x,&y,dir);
                    // cout<<x<<y<<endl;
                }
                else{
                    dir = update(instructions[j],dir);
                }
                j++;
            }
        }
        
        if(x==0 && y==0){
            return true;
        }
        return false;
    }
};