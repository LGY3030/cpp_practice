//Solution 1
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for(auto&i:arr){
            pq.push({abs(i-x), i});
            if(pq.size()>k) pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            res.push_back(temp.second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//Solution 2
class Solution {
public:
    int binary(vector<int>& arr, int x){
        int l=0;
        int r=arr.size()-1;
        while(r>=l){
            int mid=l+(r-l)/2;
            if(arr[mid]>=x) r=mid-1;
            else l=mid+1;
        }
        if(r<0) return l;
        if(l>=arr.size()-1) return r;
        if(abs(arr[l]-x)<abs(arr[r]-x)) return l;
        else return r;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx=binary(arr, x);
        int l=idx;
        int r=idx;
        k--;
        while(k){
            if(l-1>=0 && r+1<arr.size()){
                if(abs(arr[l-1]-x)<=abs(arr[r+1]-x)) l--;
                else r++;
            }
            else if(l-1>=0) l--;
            else r++;
            k--;
        }
        vector<int> res;
        for(int i=l; i<=r; i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};
