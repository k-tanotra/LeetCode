class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int zeros=0,ones=0,twos = 0;
        for(int i=0;i<nums.size();i++){
           switch(nums[i]){
               case 0:
                    zeros+=1;
                    break;
               case 1:
                    ones+=1;
                    break;
               case 2:
                    twos+=1;
                    break;
           }
        }
        //cout<<ones<<" "<<twos<<" "<<zeros<<endl;
        for(int i=0;i<zeros;i++){
            nums[i] = 0;
        }
        for(int i=zeros;i<zeros+ones;i++){
            nums[i] = 1;
        }
        for(int i=zeros+ones;i<zeros+ones+twos;i++){
            nums[i] = 2;
        }
    }
};