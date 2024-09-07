class Solution {
public:
    int countCollisions(string directions) {
       int left = 0;
       int right = 0;
       int ans = 0;
       int still =0;
       for(char c:directions){
           if(c=='R'){
                right++;
                still=0;
           }
           else if(c=='L'){
                
                if(right>0){
                    ans += 2;
                    right--;
                    if(right>0)
                        ans+=right;
                    right =0;
                    still = 1;
                    left=0;
                }
                else if(still>0){
                    ans += 1;
                    left=0;
                }
                else{
                    left++;
                }
           }
           else{
                if(right>0){
                    ans+=right;
                    right = 0;
                }
                still=1;
           }
           //cout<<c<<" -- "<<left<<" "<<right<<" "<<still<<" -- "<<ans<<endl;
       }
       return ans;
    }
};