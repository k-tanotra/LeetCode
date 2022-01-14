class Solution {
public:
    void print(vector<int> a){
        for(int x:a){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    void printWindow(string s,int start,int end){
        for(int i=start;i<=end;i++){
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
    int check(vector<int> a,vector<int> b){
        if(a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2] && a[3]>=b[3]){
            return true;
        }
        return false;
    }
    int wind(string s,vector<int> target){
        int start = 0;
        int end = -1;
        int n = s.length();
        vector<int> freq(4,0);
        unordered_map<char,int> m = {{'Q',0},{'W',1},{'E',2},{'R',3}};
        int mn = INT_MAX;
        while(end<n){
            if(check(freq,target)){
                if(mn>end-start+1){
                    mn = end-start+1;
                }
                freq[m[s[start]]]--;
                if(freq[m[s[start]]]<0){
                    freq[m[s[start]]] = 0;
                }
                start++;
            }
            else{
                end++;
                freq[m[s[end]]]++;
            }
        }
        return mn;
    }
    int balancedString(string s) {
        vector<int> arr(4,0); // 0-Q , 1-W, 2-E, 3-R
        int n = s.length();
       // cout<<n<<endl;
        n = n/4;
        for(char c: s){
            switch(c){
                case 'Q':
                    arr[0]++;
                    break;
                case 'W':
                    arr[1]++;
                    break;
                case 'E':
                    arr[2]++;
                    break;
                case 'R':
                    arr[3]++;
                    break;
                default:
                    break;
            }
        }
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>n){
                arr[i]= arr[i]-n;
                ans+=arr[i];
            }
            else{
                arr[i] = 0;
            }
        }
        if(ans==0){
            return 0;
        }
        return wind(s,arr);
    }
};