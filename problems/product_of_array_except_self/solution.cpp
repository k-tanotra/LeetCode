class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> product(n,1);
        vector<int> product2(n,1);
        int k = 0;
        for(int i=1;i<n;i++){
            product[i] = product[i-1]*nums[k];
            k++;
        }
        k=n-1;
        for(int i=n-2;i>=0;i--){
            product2[i] = product2[i+1]*nums[k];
            k--;
        }

        for(int i=0;i<n;i++){
            product[i] = product[i]*product2[i];
        }
        return product;
    }
};
