class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int num = 0;
        for(int i=0;i<n;i++){
            if(i+1<n && s[i]=='I' && s[i+1]=='V'){
                num += 4;
                i++;
            }
            else if(i+1<n && s[i]=='I' && s[i+1]=='X'){
                num += 9;
                i++;
            }
            else if(i+1<n && s[i]=='X' && s[i+1]=='L'){
                num += 40;
                i++;
            }
            else if(i+1<n && s[i]=='X' && s[i+1]=='C'){
                num += 90;
                i++;
            }
            else if(i+1<n && s[i]=='C' && s[i+1]=='D'){
                num += 400;
                i++;
            }
            else if(i+1<n && s[i]=='C' && s[i+1]=='M'){
                num += 900;
                i++;
            }
            else if(s[i]=='I'){
                num += 1;
            }
            else if(s[i]=='V'){
                num += 5;
            }
            else if(s[i]=='X'){
                num += 10;
            }
            else if(s[i]=='L'){
                num += 50;
            }
            else if(s[i]=='C'){
                num += 100;
            }
            else if(s[i]=='D'){
                num += 500;
            }
            else if(s[i]=='M'){
                num += 1000;
            }
        }
        return num;
    }
};