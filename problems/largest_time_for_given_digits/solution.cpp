class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string ans = "";
        int hoursMx = -1;
        int minMx = -1;
        sort(arr.begin(),arr.end());
        do{
            int hours = arr[0]*10 + arr[1];
            int min = arr[2]*10 + arr[3];
            cout<<hours<<" "<<min<<endl;
            if(hours>=0 && hours<=23 && min>=0 && min<=59){
                 if(hours>hoursMx){
                    hoursMx = hours;
                    minMx  = min;
                    ans = "";
                    ans += to_string(arr[0]);
                    ans += to_string(arr[1]);
                    ans+= ":";
                    ans += to_string(arr[2]);
                    ans += to_string(arr[3]);
                 }
                 else if(hours==hoursMx && min>minMx){
                    minMx  = min;
                    ans = "";
                    ans += to_string(arr[0]);
                    ans += to_string(arr[1]);
                    ans+= ":";
                    ans += to_string(arr[2]);
                    ans += to_string(arr[3]);
                 }
            }
        }while(next_permutation(arr.begin(),arr.end()));
        return ans;
    }
};