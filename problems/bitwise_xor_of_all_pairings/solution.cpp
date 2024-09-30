class Solution {
public:
    int calXor(vector<int> &v){
        int res = 0;
        for(int i=0;i<v.size();i++){
            res ^=v[i];
        }
        return res;
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        //cout<<a<<" "<<b<<endl;
        if(a%2==0 && b%2==0){
            return 0;
        }
        else if(a%2==0 && b%2!=0){
            return calXor(nums1);
        }
        else if(a%2!=0 && b%2==0){
            return calXor(nums2);
        }
        return calXor(nums1)^calXor(nums2);
    }
};
/*
a1, a2, a3
b1, b2 , b3,b4

a1^b1 ^ a1^b2 ^ a1^b3 ^ a1^b4
a2^b1 ^ a2^b2 ^ a2^b3 ^ a2^b4
a3^b1 ^ a3^b3 ^ a3^b3 ^ a3^b4
*/