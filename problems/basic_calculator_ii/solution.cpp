class Solution {
public:
    int calculate(string s) {
        vector<string> nums;
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                nums.push_back(ans);
                string x = "";
                x+=s[i];
                nums.push_back(x);
                ans="";
            }
            else{
                ans += s[i];
            }
        }
        if(ans.size()!=0){
            nums.push_back(ans);
        }
         /*
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        */
        
        
        
        //division
        //cout<<endl;
        vector<string> n2;
        for(int i=0;i<nums.size();i++){
            //cout<<"**"<<nums[i]<<endl;
            if(nums[i]=="/"){
                int k = n2.size()-1;
                n2[k] = to_string(stoi(n2[k])/stoi(nums[i+1]));
                i++;
            }
            else if(nums[i]=="*"){
                int k = n2.size()-1;
                n2[k] = to_string(stoi(n2[k]) * stoi(nums[i+1]));
                i++;
            }
            else{
               n2.push_back(nums[i]); 
            }
        }
        
        cout<<endl;
        for(int i=0;i<n2.size();i++){
            cout<<n2[i]<<" ";
        }
        
        
        
        //multiplication
        /*
        nums=n2;
        n2.clear();
        for(int i=0;i<nums.size();i++){
            if(nums[i]=="*"){
                int k = n2.size()-1;
                n2[k] = to_string(stoi(n2[k]) * stoi(nums[i+1]));
                i++;
            }
            else{
               n2.push_back(nums[i]); 
            }
        }
    
        cout<<endl;
        for(int i=0;i<n2.size();i++){
            cout<<n2[i]<<" ";
        }*/
        
        
        //add subtract
        nums=n2;
        n2.clear();
        for(int i=0;i<nums.size();i++){
            if(nums[i]=="+"){
                int k = n2.size()-1;
                n2[k] = to_string(stoi(n2[k]) + stoi(nums[i+1]));
                i++;
            }
            else if(nums[i]=="-"){
                int k = n2.size()-1;
                n2[k] = to_string(stoi(n2[k]) - stoi(nums[i+1]));
                i++;
            }
            else{
               n2.push_back(nums[i]); 
            }
        }
        /*
        cout<<endl;
        for(int i=0;i<n2.size();i++){
            cout<<n2[i]<<" ";
        }
        */
        
        
        return stoi(n2[0]);
    }
};