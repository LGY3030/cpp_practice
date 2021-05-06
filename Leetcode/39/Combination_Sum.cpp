//Solution 1
class Solution {
private:
    void cal(vector<vector<int>>& res, vector<int> vec, vector<int>& candidates, int target, int idx){
        if(target<0) return;
        for(int i=idx; i<candidates.size(); i++){
            vec.push_back(candidates[i]);
            int tmp=target-candidates[i];
            if(tmp==0) res.push_back(vec);
            else cal(res, vec, candidates, tmp, i);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        cal(res, {}, candidates, target, 0);
        return res;
    }
};


//Solution 2
class Solution {
private:
    void cal(vector<vector<int>>& res, vector<int> vec, vector<int>& candidates, int target, int idx){
        if(target==0){
            res.push_back(vec);
            return;
        }
        for(int i=idx; i<candidates.size() && target>=candidates[i]; i++){
            vec.push_back(candidates[i]);
            cal(res, vec, candidates, target-candidates[i], i);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        cal(res, {}, candidates, target, 0);
        return res;
    }
};
