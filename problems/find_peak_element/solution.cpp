class Solution {
public:
    bool isPeak(int a,int b, int c){
        if(a>b && a>c){
            return true;
        }
        return false;
    }
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            //cout<<start<<" "<<end<<" "<<mid<<endl;
            int left = (mid-1>= 0) ?  nums[mid-1] : INT_MIN;
            int right = (mid+1< nums.size()) ?  nums[mid+1] : INT_MIN;
            //cout<<nums[mid]<<" "<<left<<" "<<right<<endl;
            if(isPeak(nums[mid],left,right)){
                return mid;
            }
            else if(nums[mid]<left){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return 0;
    }
};