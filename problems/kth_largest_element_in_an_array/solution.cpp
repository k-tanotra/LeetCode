class Solution {
public:
    int partition(vector<int> &nums,int start,int end,int pivot){
        int i = start;
        int x = nums[pivot];
        swap(nums[end],nums[pivot]);
        for(int j=start;j<end;j++){
            if(nums[j]<=x){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[end]);
        return i;
    }
    int partition2(vector<int> &nums,int start,int end,int pivot){
        int i = start;
        int x = nums[pivot];
        swap(nums[end],nums[pivot]);
        for(int j=start;j<end;j++){
            if(nums[j]>=x){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[end]);
        return i;
    }
    void print(vector<int> &nums){
        for(int num:nums){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    int quickSel(vector<int> &nums,int start,int end,int k){
        if(start==end){
            return nums[start];
        }
        int pivot = start + (end-start)/2;
        int idx = partition2(nums,start,end,pivot);
       // cout<<idx<<endl;
       // print(nums);
        if(idx==k){
            return nums[idx];
        }
        else if(idx>k){
            return quickSel(nums,start,idx-1,k);
        }
        return quickSel(nums,idx+1,end,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size()-1;
        return quickSel(nums,start,end,k-1);
    }
};