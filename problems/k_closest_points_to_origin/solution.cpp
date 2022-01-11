class Solution {
public:
    int partition(vector<int> &dist,int start,int end,int pivot){
        int i = start;
        int x = dist[pivot];
        swap(dist[end],dist[pivot]);
        //cout<<"in"<<endl;
        //print(dist);
        for(int j=start;j<end;j++){
            if(dist[j]<=x){
                swap(dist[j],dist[i]);
                i++;
            }
        }
        swap(dist[i],dist[end]);
        //cout<<"ehy noy"<<endl;
        //print(dist);
        return i;
    }
    int quickSelect(vector<int> &dist,int start,int end,int k){
        if(start==end){
            return start;
        }
        int pivot = start + (end-start)/2;
        //cout<<start<<" "<<end<<" "<<pivot<<endl;
        //cout<<"cj"<<endl;
        //print(dist);
        int idx = partition(dist,start,end,pivot);
        //cout<<"ji--"<<idx<<endl;
        //print(dist);
        if(idx==k){
            return idx;
        }
        else if(idx>k){
            return quickSelect(dist,start,idx-1,k);
        }
        return quickSelect(dist,idx+1,end,k);
    }
    void print(vector<int> dist){
        for(int num:dist){
            cout<<num<<" ";
        }
        cout<<endl;
        /*
        sort(dist.begin(),dist.end());
        for(int num:dist){
            cout<<num<<" ";
        }
        cout<<endl;
        */
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> dist;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<points.size();i++){
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            dist.push_back(distance);
            m[distance].push_back(points[i][0]);
            m[distance].push_back(points[i][1]);
        }
        
        //print(dist);
        int start = 0;
        int end = dist.size()-1;
        
        vector<vector<int>> ans;
        int idx = quickSelect(dist,start,end,k-1);
        //cout<<"out "<<idx<<endl;
        //print(dist);
        unordered_set<int> fd;
        int len = 0;
        for(int i=0;i<dist.size() && len<=idx;i++){
            if(fd.find(dist[i])!=fd.end()){
                continue;
            }
            vector<int> x = m[dist[i]];
            //cout<<endl;
            bool in = false;
            for(int j=0;j<x.size() && len<=idx;j+=2){
                vector<int> y;
                y.push_back((x[j]));
                y.push_back((x[j+1]));
                ans.push_back(y);
                len++;
                in = true;
            }
            fd.insert(dist[i]);
            if(!in){
                len++;
            }
        }
        return ans;
    }
};