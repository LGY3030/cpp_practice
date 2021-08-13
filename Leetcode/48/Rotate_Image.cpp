class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==1) return;
        for(int i=0; i<matrix.size()/2; i++){
            int first=i;
            int last=matrix.size()-1-i;
            for(int j=first; j<last; j++){
                int temp=matrix[first][j];
                matrix[first][j]=matrix[last-(j-first)][i];
                matrix[last-(j-first)][i]=matrix[last][last-(j-first)];
                matrix[last][last-(j-first)]=matrix[first+(j-first)][last];
                matrix[first+(j-first)][last]=temp;
            }
        }
        return;
    }
};
