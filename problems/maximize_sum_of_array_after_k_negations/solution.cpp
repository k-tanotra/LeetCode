class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int neg=0;
        int abs_min = INT_MAX;
        int mini = INT_MAX;
        
        int sum = 0;
        int abs_sum  = 0;
        int p_idx = -1;
        int sum_p =0;
        int sum_neg=0;
        
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg++;
                sum_neg+=nums[i];
            }
            else if(nums[i]>=0){
                if(p_idx==-1)
                    p_idx = i;
                sum_p+=nums[i];
            }
            
            abs_sum += abs(nums[i]);
            abs_min = min(abs_min,abs(nums[i]));
        }
        
        
        cout<<sum_p<<" "<<sum_neg<<" "<<abs_sum<<" "<<abs_min<<" "<<neg<<endl;
        if(k>=neg){
            k-=neg;
            if(k%2==0){
                return abs_sum;
            }
            else{
                return abs_sum -  2*abs_min;
            }
        }
        else{
            int sum_k=0;
            for(int i=0;i<k;i++){
                sum_k+=nums[i];
            }
            cout<<sum_k<<endl;
            return sum_p - (abs(sum_neg) - abs(sum_k)) + abs(sum_k);
        }
    }
};