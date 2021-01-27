struct twonum{
    int first;
    int second;
};

//sort ��compare function�n�O���q�禡�άOclass�̪�static�禡, �ҥH�i�H��cmp function ����class�~���άO�g�bclass�̭��M��[static 
bool cmp(twonum a, twonum b){
    return a.second>b.second;
}
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto&i:nums) umap[i]++;
        
        vector<twonum> vec; 
        twonum twon;
        for(auto&i:umap){
            twon.first=i.first;
            twon.second=i.second;
            vec.push_back(twon);
        }
        sort(vec.begin(), vec.end(), cmp);
        
        vector<int> res;
        for(int i=0;i<k;i++) res.push_back(vec[i].first);
        return res;
    }
};
