class Solution {
public:
    int findLower(vector<int>& nums1, vector<int>& nums2,int s){
        int start = 0;
        int end = nums1.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            int x = upper_bound(nums2.begin(),nums2.end(),nums1[mid]) - nums2.begin();
            int y = lower_bound(nums2.begin(),nums2.end(),nums1[mid]) - nums2.begin();
            int b = mid+x;
            int a = mid+y;
            if(a<=s && s<=b){
                return nums1[mid];
            }
            else if(mid+x>s){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        start = 0;
        end = nums2.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            int x = upper_bound(nums1.begin(),nums1.end(),nums2[mid]) - nums1.begin();
            int y = lower_bound(nums1.begin(),nums1.end(),nums2[mid]) - nums1.begin();
            int b = mid+x;
            int a = mid+y;
            if(a<=s && s<=b){
                return nums2[mid];
            }
            else if(mid+x>s){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return 0;
    }
    int findUpper(vector<int>& nums1, vector<int>& nums2,int s){
        int start = 0;
        int end = nums1.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            int x = upper_bound(nums2.begin(),nums2.end(),nums1[mid]) - nums2.begin();
            int y = lower_bound(nums2.begin(),nums2.end(),nums1[mid]) - nums2.begin();
            int b = nums1.size()-1-mid+nums2.size()-x;
            int a = nums1.size()-1-mid+nums2.size()-y;
            if(b<=s && s<=a){
                return nums1[mid];
            }
            else if(nums1.size()-1-mid+nums2.size()-x>s){
                start = mid + 1;
            }
            else{
                end =  mid - 1;
            }
        }

        start = 0;
        end = nums2.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            int x = upper_bound(nums1.begin(),nums1.end(),nums2[mid]) - nums1.begin();
            int y = lower_bound(nums1.begin(),nums1.end(),nums2[mid]) - nums1.begin();
            int b = nums2.size()-1-mid+nums1.size()-x;
            int a = nums2.size()-1-mid+nums1.size()-y;
            if(b<=s && s<=a){
                return nums2[mid];
            }
            else if(nums2.size()-1-mid+nums1.size()-x>s){
                start = mid + 1;
            }
            else{
                end =  mid - 1;
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int b = (len1+len2)%2==0 ? (len1+len2-2)/2 : (len1+len2-1)/2;
        double ans = 0.00000;
        if((len1+len2)%2==0){
            int m1 = findLower(nums1,nums2,b);
            int m2 = findUpper(nums1,nums2,b);
            ans = (m1+m2)/2.00000;
        }
        else{
            int m1 = findLower(nums1,nums2,b);
            ans = m1*1.00000;
        }
        return ans;
    }
};