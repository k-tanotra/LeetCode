class Solution {
public:
    void print(vector<int> &nums){
        for(int n:nums){
            cout<<n<<" ";
        }
        cout<<"\n"<<endl;
    }
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
                i=j;
            }
            else{
                i++;
            }
            k++;
        }
        cout<<k<<endl;
        return k;
    }
};