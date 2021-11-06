class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int rp = -1;
        int ans = -1;
        while(start<end){
            int mid = start + (end-start)/2;
            if(mid-1>=0 && mid+1<=nums.size() && nums[mid-1]>nums[mid] && nums[mid+1]>nums[mid]){
                rp = mid;
                break;
            }
            else if(nums[mid]>nums[end]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        if(rp==-1){
            rp = start;
        }
        // cout<<rp<<endl;
        int st = rp;
        int next = rp==0? rp =0:rp=rp-1;
        if(target>=nums[0] && target<=nums[next]){
            start = 0;
            end = next;
        }
        else{
            end = nums.size()-1;
            start = st;
        }
        cout<<start<<" "<<end<<endl;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                ans = mid;
                break;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return ans;
        
    }
};