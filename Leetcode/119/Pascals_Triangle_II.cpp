class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0 || rowIndex==1) return vector<int>(rowIndex+1, 1);
        vector<int> pre=vector<int>(2, 1);
        for(int i=2; i<=rowIndex; i++){
            vector<int> temp=vector<int>(i+1, 1);
            for(int j=1; j<i; j++){
                temp[j]=pre[j-1]+pre[j];
            }
            if(i==rowIndex) return temp;
            pre=temp;
        }
        return {};
    }
};
