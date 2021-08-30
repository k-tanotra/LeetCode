class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> low;
        vector<int> high;
        map<char,int> m;
        
        vector<int> ans;
        int i=0;
        int index=0;
        while(s[i]!='\0'){
            if(m.find(s[i])==m.end()){
                m.insert({s[i],index});
                low.push_back(i);
                high.push_back(i);
                index++;
            }
            
            else{
                high[m[s[i]]] = i;
            }
            i++;
        }
        
        int len = low.size();
        int g_low = low[0];
        int g_high = high[0];
        for(int i=0;i<len;i++){
            if(g_high < low[i]){
                ans.push_back(g_high-g_low+1);
                g_low = low[i];
                g_high = high[i];
            }
            else if(high[i]>g_high){
                g_high = high[i];
            }
        }
        ans.push_back(g_high-g_low+1);
        
        return ans;
    }
};