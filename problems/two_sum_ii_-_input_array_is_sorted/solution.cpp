class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int end = numbers.size()-1;
        while(left<end){
            if(numbers[left]+numbers[end] == target){
                return {left+1,end+1};
            }
            else if(numbers[left]+numbers[end] > target){
                end--;
            }
            else{
                left++;
            }
        }
        return {};
    }
};