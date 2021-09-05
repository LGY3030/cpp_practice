class Solution {
public:
    struct simpleHash{
        size_t operator()(const pair<int, int>& a) const {
            return a.first^a.second;
        }  
    };
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<3) return points.size();
        int res=0;
        for(int i=0; i<points.size()-1; i++){
            unordered_map<pair<int, int>, int, simpleHash> umap;
            int vertical=0;
            int same=0;
            for(int j=i+1; j<points.size(); j++){
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1]){
                    same++;
                    continue;
                }
                else if(points[i][0]==points[j][0]){
                    vertical++;
                    continue;
                }
                else{
                    int a=points[j][0]-points[i][0];
                    int b=points[j][1]-points[i][1];
                    int gcd=GCD(a, b);
                    umap[{a/gcd, b/gcd}]++;
                }
            }
            int count=0;
            for(auto&map:umap) count=max(count, map.second);
            count=max(count, vertical);
            count+=same;
            res=max(res, count+1);
        }
        return res;
    }
    
    int GCD(int a, int b){
        if(b==0) return a;
        return GCD(b, a%b);
    }
};
