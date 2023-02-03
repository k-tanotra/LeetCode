class Solution {
public:
    bool isValid(int hour,int min){
        if(hour<=23 && min<=59){
            return true;
        }
        return false;
    }
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mxHour = -1;
        int mxMin = -1;
        do{
            if(isValid(arr[0]*10+arr[1],arr[2]*10+arr[3])){
                if(arr[0]*10+arr[1]>mxHour){
                    mxHour = arr[0]*10+arr[1];
                    mxMin = arr[2]*10+arr[3];
                }
                else if(arr[0]*10+arr[1]==mxHour && arr[2]*10+arr[3]>mxMin){
                    mxMin = arr[2]*10+arr[3];
                }
            }
        }while(next_permutation(arr.begin(), arr.end()));

        if(mxHour==-1)
            return "";
        
        string h = to_string(mxHour);
        string m = to_string(mxMin);
        if(h.size()==1){
            h = "0" + h;
        }
        if(m.size()==1){
            m = "0" + m;
        }
        return h + ":" + m;
    }
};