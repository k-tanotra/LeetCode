class SparseVector {
public:
    unordered_map<int,int> s;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                s.insert({i,nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        //ctor<int> v2 = vec.num;
        int ans = 0;
        for(auto itr=s.begin();itr!=s.end();itr++){
            if(vec.s.find(itr->first)!=vec.s.end()){
                ans+= itr->second * vec.s[itr->first];
            }
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);