class SparseVector {
public:
    vector<pair<int,int>> v;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                v.push_back({i,nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        int s1 = 0;
        int s2 = 0;
        while(s1<v.size() && s2<vec.v.size()){
            if(v[s1].first==vec.v[s2].first){
                ans+= v[s1].second * vec.v[s2].second;
                s1++;
                s2++;
            }
            else if(v[s1].first>vec.v[s2].first){
                s2++;
            }
            else{
                s1++;
            }
        }
        
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);