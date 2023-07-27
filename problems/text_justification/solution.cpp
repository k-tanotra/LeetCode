class Solution {
public:
    string justify(vector<string> &line,int maxWidth){
        int noOfWords = line.size();
        int spaces;
        int len = 0;
        string res = "";
        for(int i=0;i<line.size();i++){
            len += line[i].size();
        }
        int rem = 0;
        if(noOfWords>1){
            spaces = (maxWidth-len)/(noOfWords-1);
            rem = (maxWidth-len)%(noOfWords-1);
        }
        else{
            spaces = maxWidth-len;
        }
        
        int totalSpaces = maxWidth-len;
        for(int i=0;i<line.size();i++){
            res += line[i];
            if(totalSpaces>0){
                for(int j=0;j<spaces;j++){
                    res+=" ";
                }
                totalSpaces -= spaces;
            }
            if(rem>0){
                res+=" ";
                rem--;
                totalSpaces -= 1;
            }
        }
        return res;
    }
    string leftAlign(vector<string> &line,int maxWidth){
        string res = "";
        for(int i=0;i<line.size();i++){
            res += line[i];
            if(i!=line.size()-1){
                res += " ";
            }
        }
        while(res.size()<maxWidth){
            res+= " ";
        }
        return res;
    }
    void print(vector<string> &line){
        for(string s:line){
            cout<<s<<" ";
        }
        cout<<"\n";
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int noOfWords = 0;
        int curLen = 0;
        vector<string> ans;
        vector<string> line;
        for(int i=0;i<n;i++){
            if(curLen + words[i].size()+noOfWords<=maxWidth){
                //cout<<"ADD+___"<<endl;
                //cout<<words[i].size()+noOfWords<<endl;
                //cout<<words[i]<<endl;
                line.push_back(words[i]);
                curLen += words[i].size()+noOfWords;
                noOfWords = 1;
            }
            else{
                //cout<<"IN _____"<<endl;
                //print(line);
                noOfWords = 0;
                curLen = 0;
                if(line.size()>0){
                    //cout<<"AAAAA"<<endl;
                   ans.push_back(justify(line,maxWidth));
                }
                line = {};
                line.push_back(words[i]);
                curLen += words[i].size()+noOfWords;
                noOfWords = 1;
            }
        }
        if(line.size()>0){
           ans.push_back(leftAlign(line,maxWidth));
        }
        return ans;
    }
};