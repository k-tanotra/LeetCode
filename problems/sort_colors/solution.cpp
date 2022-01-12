class Solution {
public:
    void print(vector<int> arr){
        for(int n:arr){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;
        while(mid<=end){
            if(nums[mid]==0){
                swap(nums[mid],nums[start]);
                start++; mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[end]);
                end--;
            }
            else{
                mid++;
            }
        }
    }
};