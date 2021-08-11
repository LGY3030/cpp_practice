class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool leftflag=false;
        bool rightflag=false;
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0]==0) leftflag=true;
        }
        for(int i=0; i<matrix[0].size(); i++){
            if(matrix[0][i]==0) rightflag=true;
        }
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1; i<matrix.size(); i++){
            if(matrix[i][0]==0){
                for(int j=1; j<matrix[0].size(); j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=1; i<matrix[0].size(); i++){
            if(matrix[0][i]==0){
                for(int j=1; j<matrix.size(); j++){
                    matrix[j][i]=0;
                }
            }
        }
        if(leftflag){
            for(int i=0; i<matrix.size(); i++){
                matrix[i][0]=0;
            }
        }
        if(rightflag){
            for(int i=0; i<matrix[0].size(); i++){
                matrix[0][i]=0;
            }
        }
    }
};
