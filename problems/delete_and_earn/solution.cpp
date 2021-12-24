class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> numLine(10001,0);
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            numLine[nums[i]] += nums[i];
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
            }
        }
        /*
        cout<<endl;
        for(int i=0;i<11;i++){
            cout<<numLine[i]<<" ";
        }
        */
        
        int ans = numLine[1];
        for(int i=2;i<numLine.size();i++){
            if(s.find(i)==s.end()){
                numLine[i]=ans;
                continue;
            }
            if(s.find(i-1)!=s.end()){
                numLine[i] = max(ans,numLine[i-2]+numLine[i]);
            }
            else
                numLine[i] += numLine[i-1];
            ans = max(numLine[i],ans);
        }
        /*
        cout<<endl;
        for(int i=0;i<11;i++){
            cout<<numLine[i]<<" ";
        }
        */
        
        return ans;
    }
};