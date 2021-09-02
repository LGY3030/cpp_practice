class Solution {
private:
    vector<vector<int>> vec={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> check(image.size(), vector<bool>(image[0].size(), false));
        stack<pair<int, int>> stk;
        int floodnum=image[sr][sc];
        stk.push({sr, sc});
        while(!stk.empty()){
            auto temp=stk.top();
            stk.pop();
            image[temp.first][temp.second]=newColor;
            check[temp.first][temp.second]=true;
            for(auto&i:vec){
                int row=temp.first+i[0];
                int column=temp.second+i[1];
                if(row>=0 && row<image.size() && column>=0 && column<image[0].size() && image[row][column]==floodnum && !check[row][column]) stk.push({row, column});
            }
        }
        return image;
    }
};
