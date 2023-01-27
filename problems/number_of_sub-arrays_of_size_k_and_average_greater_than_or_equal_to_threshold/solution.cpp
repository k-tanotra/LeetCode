class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int count = 0;
        for(int i=0;i<arr.size();i++){
            if(i<k){
                sum += arr[i];
            }
            else{
                sum -= arr[i-k];
                sum += arr[i];
            }
            if(i>=k-1){
                if(sum/k >= threshold){
                    count++;
                }
            }
        }
        return count;
    }
};