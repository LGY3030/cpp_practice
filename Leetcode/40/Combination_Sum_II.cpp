class Solution {
private:
    void cal(vector<vector<int>>& res, vector<int>& candidates, int target, int idx, vector<int> vec){
        if(target==0){
            res.push_back(vec);
            return;
        }
        for(int i=idx; i<candidates.size() && target>=candidates[i]; i++){
            if(i>=1 && i-1>=idx && candidates[i]==candidates[i-1]) continue;
            vec.push_back(candidates[i]);
            cal(res, candidates, target-candidates[i], i+1, vec);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        cal(res, candidates, target, 0, {});
        return res;
    }
};
