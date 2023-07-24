class Solution {
public:
    void flipAtIndex(vector<int> &nums1,int from,int to){
        int start = from;
        int end = to-1;
        while(start<=end){
            swap(nums1[start],nums1[end]);
            start++;
            end--;
        }
    }
    void print(vector<int> &nums1){
        for(int n:nums1){
            cout<<n<<" ";
        }
        cout<<"\n"<<endl;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = m;
        while(i<m || j<n){
            if(i<m && j<n){
                if(nums1[i]<=nums2[j]){
                    nums1[k] = nums1[i];
                    i++;
                }
                else{
                    nums1[k] =nums2[j];
                    j++;
                }
            }
            else if(i<m){
                //nums1[k] = nums1[i];
                i++;
            }
            else if(j<n){
                nums1[k]= nums2[j];
                j++;
            }
            k = (k+1)%(m+n);
        }
        //print(nums1);
        flipAtIndex(nums1,0,m);
        //print(nums1);
        flipAtIndex(nums1,m,m+n);
        //print(nums1);
        flipAtIndex(nums1,0,m+n);
        //print(nums1);
    }
};