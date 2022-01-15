class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        list<int> li;
        int n = deck.size();
        li.push_back(deck[n-1]);
        
        int end = n-2;
        while(end>=0){
            li.push_back(deck[end]);
            int x = li.back();
            li.pop_back();
            int y = li.back();
            li.pop_back();
            li.push_front(y);
            li.push_front(x);
            end--;
        }
        
        vector<int> ans;
        for(auto itr=li.begin();itr!=li.end();itr++){
            ans.push_back(*itr);
        }
        
        return ans;
    }
};