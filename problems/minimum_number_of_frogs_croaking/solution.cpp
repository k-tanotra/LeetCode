class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        map<char,int> freq;
        freq.insert({'c',0});
        freq.insert({'r',0});
        freq.insert({'o',0});
        freq.insert({'a',0});
        freq.insert({'k',0});
        
        int ans = 0;
        int max  = 0;
        int len = croakOfFrogs.length();
        for(int i=0;i<len;i++){
            
            if(croakOfFrogs[i]=='c'){
                freq[croakOfFrogs[i]]++;
            }
            else if(croakOfFrogs[i]=='r' && freq['c']>freq['r']){
                 freq[croakOfFrogs[i]]++;
            }
            else if(croakOfFrogs[i]=='o' && freq['r']>freq['o']){
                 freq[croakOfFrogs[i]]++;
            }
            else if(croakOfFrogs[i]=='a' && freq['o']>freq['a']){
                freq[croakOfFrogs[i]]++;
            }
            else if(croakOfFrogs[i]=='k' && freq['a']>freq['k']){
                freq[croakOfFrogs[i]]++;
            }
            else{
                return -1;
            }
            
            if(croakOfFrogs[i]=='k'){
                
                bool check = true;
                for(auto it=freq.begin();it!=freq.end();it++){
                    if(it->second<=0){
                        check = false;
                        break;
                    }
                }
                if(check){
                    freq['c']--;
                    freq['r']--;
                    freq['o']--;
                    freq['a']--;
                    freq['k']--;
                    
                    max++;
                    if(max>ans){
                        ans = max;
                    }
                }
                if(check){
                    max = freq['c'];
                }
            }
        }
        if(freq['c']!=0 || freq['r']!=0 || freq['o']!=0 || freq['a']!=0 || freq['k']!=0){
            return -1;
        }
        return ans;
    }
};