//Solution 1
class Solution {
private:
    void help(vector<vector<int>> &res, vector<int> vec, int k, int n, int now, int total){
        if(k==0){
            if(n==0) res.push_back(vec);
            return;
        }
        for(int i=now; i<=9 && i<=n && total>=n; i++){
        	total-=i;
            vec.push_back(i);
            help(res, vec, k-1, n-i, i+1, total);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        help(res, {}, k, n, 1, 45);
        return res;
    }
};

//Solution 2
class Solution {
private:
    void bk(vector<vector<int>>& res, int& k, int &n, int idx, vector<int> vec, int now){
        if(vec.size()==k){
            if(now==n) res.push_back(vec);
            return;
        }
        for(int i=idx; i<=10-k+vec.size(); i++){
            vec.push_back(i);
            bk(res, k, n, i+1, vec, now+i);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        bk(res, k, n, 1, {}, 0);
        return res;
    }
};
