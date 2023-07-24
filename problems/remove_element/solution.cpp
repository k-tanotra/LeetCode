class Solution {
public:
    void print(vector<int> &nums){
        for(int n:nums){
            cout<<n<<" ";
        }
        cout<<"\n"<<endl;
    }
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int k=0;k<nums.size();k++){
            if(nums[k]!=val){
                swap(nums[j],nums[k]);
                j++;
            }
        }
        //print(nums);
        return j;
    }
};