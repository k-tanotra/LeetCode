class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> m;
        for(int i=0;i<tops.size();i++){
            m[tops[i]]++;
            m[bottoms[i]]++;
        }
        for(auto itr=m.begin();itr!=m.end();itr++){
            if(itr->second>=tops.size()){
                int c = 0;
                int x = 0;
                int w = true;
                for(int i=0;i<tops.size();i++){
                    if(tops[i]!=itr->first && bottoms[i]!=itr->first){
                        w = false;
                        break;
                    }
                    if(tops[i]==itr->first && bottoms[i]!=itr->first)
                        c++;
                    if(bottoms[i]==itr->first && tops[i]!=itr->first)
                        x++;
                }
                if(!w){
                    continue;
                }
                return min(x,c);
            }
        }
        return -1;
    }
};