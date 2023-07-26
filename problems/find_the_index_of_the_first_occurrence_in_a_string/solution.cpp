class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size();
        int l2 = needle.size();
        if(l2>l1){
            return -1;
        }
        for(int i=0;i<l1;i++){
            if(haystack[i]==needle[0]){
                int len = 0;
                for(int j=i;j<min(i+l2,l1);j++){
                    if(haystack[j]==needle[len]){
                        len++;
                    }
                }
                if(len==l2){
                    return i;
                }
            }
        }
        return -1;
    }
};