class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> res(box[0].size(), vector<char>(box.size()));
        for(int i=0; i<box.size(); i++){
            int slow = box[0].size()-1;
            for(int j=box[0].size()-1; j>=0; j--){
                if(box[i][j]=='#'){
                    char temp=box[i][slow];
                    box[i][slow]=box[i][j];
                    box[i][j]=temp;
                    slow--;
                }
                else if(box[i][j]=='*') slow=j-1;
            }
        }
        for(int i=0; i<box[0].size(); i++){
            for(int j=0; j<box.size(); j++){
                res[i][box.size()-j-1]=box[j][i];
            }
        }
        return res;
    }
};
