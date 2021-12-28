class Solution {
public:
    vector<string> split(string s){
        string temp = "";
        vector<string> vec;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                vec.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        if(temp.length()!=0){
            vec.push_back(temp);
        }
        return vec;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> st1 = split(sentence1);
        vector<string> st2 = split(sentence2);
        
        vector<string> temp;
        if(st2.size()>st1.size()){
            temp = st1;
            st1 = st2;
            st2 = temp;
        }
        
        int start = 0;
        int end = st2.size()-1;
        
        int start2 = 0;
        int end2 = st1.size()-1;
        
        while(start<=end){
            //cout<<start<<" "<<st2[start]<<" "<<end<<" "<<st2[end]<<endl;
            //cout<<start2<<" "<<st1[start2]<<" "<<end2<<" "<<st1[end2]<<endl;
            //cout<<endl;
            if(start==end){
                if(st1[start2]==st2[start] || st1[end2]==st2[end]){
                    start++;
                    end--;
                    start2++;
                    end2--;
                }
                else{
                    return false;
                }
            }
            else if(st1[start2]==st2[start] && st1[end2]==st2[end]){
                start++;
                end--;
                start2++;
                end2--;
            }
            else if(st1[start2]==st2[start]){
                start++;
                start2++;
            }
            else if(st1[end2]==st2[end]){
                end2--;
                end--;
            }
            else{
                //cout<<"second fuck";
                return false;
            }
        }
        return true;
    }
};