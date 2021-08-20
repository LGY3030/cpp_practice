class Solution {
private:
    unordered_set<int> uset;
public:
    bool canReach(vector<int>& arr, int start) {
        if(start<0 || start>=arr.size()) return false;
        if(arr[start]==0) return true;
        if(uset.count(start)) return false;
        uset.insert(start);
        return canReach(arr, start-arr[start])||canReach(arr, start+arr[start]);
    }
};
