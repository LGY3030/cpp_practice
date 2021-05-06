//Solution 1
class Solution {
private:
    void cal(int n, int k, vector<int> vec, int idx, vector<vector<int>>& res){
        if(vec.size()==k){
            res.push_back(vec);
            return;
        }
        for(int i=idx; i<=n; i++){
            vec.push_back(i);
            cal(n, k, vec, i+1, res);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        cal(n, k, {}, 1, res);
        return res;
    }
};

//Solution 2
class Solution {
private:
    void cal(int n, int k, vector<int> vec, int idx, vector<vector<int>>& res){
        if(vec.size()==k){
            res.push_back(vec);
            return;
        }
        for(int i=idx; i<=n && vec.size()+n+1-idx>=k; i++){
            vec.push_back(i);
            cal(n, k, vec, i+1, res);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        cal(n, k, {}, 1, res);
        return res;
    }
};

//Solution 3
class Solution {
private:
    void cal(int n, int k, vector<int>& vec, int idx, vector<vector<int>>& res){
        if(k==0){
            res.push_back(vec);
            return;
        }
        for(int i=idx; n+1-i>=k; i++){
            vec.push_back(i);
            cal(n, k-1, vec, i+1, res);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        cal(n, k, temp, 1, res);
        return res;
    }
};
