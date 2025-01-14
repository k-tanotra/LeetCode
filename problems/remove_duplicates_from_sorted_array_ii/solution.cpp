class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int n = nums.size()-1;
        int k = 0;
        for(int i=0;i<=n;){
            nums[k] = nums[i];
            if(i+1<=n && nums[i]==nums[i+1]){
                int j=i+1;
                while(j<=n && nums[i]==nums[j]){
                    j++;
                }
                k++;
                nums[k] = nums[i];
                i=j;
            }
            else{
                i++;
            }
            k++;
        }
        //cout<<k<<endl;
        return k;
    }
};