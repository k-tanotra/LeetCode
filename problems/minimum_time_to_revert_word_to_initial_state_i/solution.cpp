class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int idx = 0;
        string w = word;
        int len = word.length();
        int time = 0;
        for(int i=k;i<len;i+=k){
            string w = word.substr(i);
            //cout<<w<<" "<<time<<endl;
            time++;
            //if(w.length()<k){
            //    break;
            //}
            if(w == word.substr(0,w.length())){
                return time;
            }
        }
        return time+1;
    }
};