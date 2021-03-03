class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> umap;
        int res=0;
        for(auto&i:points) umap[i[0]].insert(i[1]);
        for(int i=0; i<points.size()-1; i++){
            for(int j=i+1; j<points.size(); j++){
                if(points[i][0]==points[j][0] || points[i][1]==points[j][1]) continue;
                int a=points[j][1];
                int b=points[i][1];
                if(umap[points[i][0]].count(a) && umap[points[j][0]].count(b)){
                    int tmp=abs(points[i][0]-points[j][0]) * abs(points[i][1]-points[j][1]);
                    if(res==0) res=tmp;
                    else res=min(res, tmp);
                }
            }
        }
        return res;
    }
};
