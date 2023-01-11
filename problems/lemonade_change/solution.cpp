class Solution {
public:
    void print(vector<int> &changeList){
        for(int n:changeList){
            cout<<n<<" ";
        }
        cout<<"\n"<<endl;
    }
    bool isPossible(vector<int> &changeList, int change){
        int n = changeList.size()-1;
        //print(changeList);
        while(n>=0 && change!=0){
            if(changeList[n]==0){
                n--;
                continue;
            }
            if(n==2){
                if(change>=20){
                    change -= 20;
                    changeList[n] -= 1;
                }
                else{
                    n--;
                }
            }
            else if(n==1){
                if(change>=10){
                    change -= 10;
                    changeList[n] -= 1;
                }
                else{
                    n--;
                }
            }
            else{
                if(change>=5){
                    change -= 5;
                    changeList[n] -= 1;
                }
                else{
                    n--;
                }
            }

        }
        return (change==0);
    }
    bool lemonadeChange(vector<int>& bills) {
        vector<int> changeList(3,0);
        int change = 0;
        for(int i=0;i<bills.size();i++){
            change = bills[i] - 5;
            if(!isPossible(changeList,change)){
                return false;
            }
            changeList[bills[i]/10]+=1;
        }
        return true;
    }
};