class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        //Method 2
        int mx = arr[0];
        int count = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>mx){
                count = 1;
                mx = arr[i];
            }
            else{
                count++;
            }
            if(count==k){
                return mx;
            }
        }
        return mx;
        // Method 1
        /*
        deque<int> dq;
        int mx = -1;
        for(int i=0;i<arr.size();i++){
            dq.push_back(arr[i]);
            mx = max(arr[i],mx);
        }
        if(k>=arr.size()){
            return mx;
        }
        int cur = 1;
        int curMax = -1;
        int prev = -1;
        do{
            int temp = dq.front();
            dq.pop_front();
            if(dq.front()>temp){
                dq.push_back(temp);
            }
            else{
                int x = dq.front();
                dq.pop_front();
                dq.push_front(temp);
                dq.push_back(x);
            }
            curMax = dq.front();
            if(curMax==prev){
                cur++;
            }
            else{
                cur = 0;
            }
            prev = curMax;
        }while(cur!=k-1);

        return curMax;
        */
    }
};