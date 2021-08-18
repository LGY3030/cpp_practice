class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<vector<bool>> vec(matrix.size(), vector<bool>(matrix[0].size(), false));
        int h=0;
        int v=0;
        vector<pair<int, int>> opt={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction=0;
        while(true){
            if(res.size()==matrix.size()*matrix[0].size()) break;
            if(h<0 || h>=matrix[0].size() || v<0 || v>=matrix.size() || vec[v][h]){
                v-=opt[direction].first;
                h-=opt[direction].second;
                direction=(direction+1)%4;
                v+=opt[direction].first;
                h+=opt[direction].second;
            }
            res.push_back(matrix[v][h]);
            vec[v][h]=true;
            v+=opt[direction].first;
            h+=opt[direction].second;
        }
        return res;
    }
};
