class Solution {
     #define ll long long
public:
    
    long long res(vector<int>& nums1, vector<int>& nums2, long long m){
        ll ans=0;
        int j = nums2.size()-1;
        for(int i=0;i<nums1.size();i++){
            while(j>=0 && 1ll*nums1[i]*nums2[j]>=m){
                j--;   
            }
            ans += j+1;
        }
        return ans;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        
        auto lb1 = lower_bound(nums1.begin() , nums1.end() , 0 ) ;
        auto lb2 = lower_bound(nums2.begin() , nums2.end() , 0 ) ;

        vector<int> neg1(begin(nums1) , lb1 ) ;
        vector<int> neg2(begin(nums2) , lb2 ) ;
        vector<int> pos1(lb1 , end(nums1));
        vector<int> pos2(lb2 , end(nums2));

        vector<int> negr1(rbegin(neg1) , rend(neg1) ) ;
        vector<int> negr2(rbegin(neg2) , rend(neg2) ) ;
        vector<int> posr1(rbegin(pos1) , rend(pos1));
        vector<int> posr2(rbegin(pos2) , rend(pos2));
        
       ll ans=0;
       ll start = -1e10;
       ll end = 1e10;
       ll count = 0;
       while(start<=end){
           
           ll mid = start + (end-start)/2;
           
           if(mid>0){
               
               count = res(negr1,negr2,mid) + res(pos1,pos2,mid) + pos1.size()*neg2.size() + pos2.size()*neg1.size();
           }
           else{
               count = res(neg1,posr2,mid) + res(neg2,posr1,mid);
           }
           
           if(count>=k){
               end = mid-1;
           }
           else{
               ans = mid;
               start = mid+1;
           }
       }
        
       return ans;
    }
};