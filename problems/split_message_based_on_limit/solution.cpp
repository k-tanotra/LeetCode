class Solution {
public:
    int check(int parts,string message,int limit){
        //cout<<"CHECKING FOR -- "<<parts<<endl;
        int idx = 1;
        int msgIdx = 0;
        int msgLen = message.size();
        for(int i=1;i<=parts;i++){
            string suff = "<" + to_string(i) + "/" + to_string(parts) + ">";
            int suffLen = suff.size();
            int reqLen = limit-suffLen;
            if(parts==98 || parts==97 ||parts==99)
                //cout<<"PART -- "<<i<<" Suffix --"<<suff<<" Len --"<<suffLen<<" -- "<<reqLen<<" IDX "<<msgIdx<<endl;
            if(reqLen<=0){
                //cout<<"Required Len cant fit"<<endl;
                return 0;
            }
            if(i!=parts){
                msgIdx+=reqLen;
                if(msgIdx>=msgLen){
                    //cout<<"MsgIdx Overflown need lesser parts"<<endl;
                    return 0;
                }
            }
            else{
                msgIdx = min(msgIdx+reqLen,msgLen);
                //cout<<"INzide last part"<<msgIdx<<endl;
                if(msgIdx<msgLen){
                   // cout<<"Last part cant fit the full string --- "<<msgIdx<<endl;
                    return 1;
                }
            }
        }
        return 2;
    }
    vector<string> splitMessage(string message, int limit) {
        int msgLen = message.size();
        //cout<<msgLen<<endl;
        int ans = INT_MAX;
        //check(99,message,limit);
        vector<vector<int>> searchSpace ={{1,9},{10,99},{100,999},{1000,9999},{10000,10000}};
        for(int i=0;i<searchSpace.size();i++){
            int start = searchSpace[i][0];
            int end = searchSpace[i][1];
            while(start<=end){
                //cout<<start<<" "<<end<<endl;
                int mid = (start+end)/2;
                //1 --> need more parts
                //0 --> reduce parts
                int t = check(mid,message,limit);
                if(t==0){
                    end = mid-1;
                }
                else if(t==1){
                    start = mid+1;
                }
                else if(t==2){
                    //found a potential answer but could go lower
                    //cout<<"potential"<<endl;
                    //cout<<mid<<endl;
                    if(mid<ans)
                        ans = mid;
                    end = mid-1;
                }
            }
        }
        if(ans==INT_MAX){
            return {};
        }
        vector<string> res;
        int beg = 0;
        for(int i=0;i<ans;i++){
            string suff = "<" + to_string(i+1) + "/" + to_string(ans) + ">";
            int reqLen = limit - suff.size();
            //cout<<reqLen<<endl;
            if(i==ans-1){
                int y = message.size()-beg+suff.size();
                reqLen=min(limit-suff.size(),message.size()-beg+suff.size());
            }
            //cout<<reqLen<<endl;
            string x = message.substr(beg,reqLen);
            beg+=reqLen;
            res.push_back(x+suff);
        }
        return res;
    }
};