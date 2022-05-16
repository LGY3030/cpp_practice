class Solution {
public:
    Solution(vector<int>& w) {
        for(auto&i:w){
            if(vec.size()==0) vec.push_back(i);
            else vec.push_back(i+vec.back());
        }
    }
    
    int pickIndex() {
        int idx = rand()%vec[vec.size()-1];
        auto it = upper_bound(vec.begin(), vec.end(), idx);
        return it-vec.begin();
    }
private:
    vector<int> vec;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
