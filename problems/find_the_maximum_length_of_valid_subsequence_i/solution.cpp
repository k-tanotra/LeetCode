class Solution {
public:
    int getAlt(vector<int>& nums, bool start){
        bool toggle = start;
        int sz = 0;
        for(int i=0;i<nums.size();i++){
            if(toggle && nums[i]%2==0){
                sz++;
                toggle=!toggle;
            }
            else if(!toggle && nums[i]%2==1){
                sz++;
                toggle=!toggle;
            }
        }
        return sz;
    }
    int maximumLength(vector<int>& nums) {
        //all even or all odd
        int even = 0;
        int odd = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                even++;
            }
            else if(nums[i]%2==1){
                odd++;
            }
        }
        
        int alt = max(getAlt(nums,true),getAlt(nums,false));
        //cout<<alt<<endl;
        return max(even,max(odd,alt));
        
    }
};