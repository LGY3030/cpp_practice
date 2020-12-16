//Using dynamic programming
//ex: 3個node, 先把第一個當root, 左邊0個, 右邊2個, 0個的組合乘上2個的組合就是這種情況的組合, 再把第二個當root, 以此類推
//因為分割成兩邊的node一定會比原本少, 所以都有再DP的紀錄裡 
class Solution {
public:
    int numTrees(int n) {
        if(n<=1) return 1;
        vector<int> vec(n+1);
        vec.at(0) = 1;
        vec.at(1) = 1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                vec.at(i)+=vec.at(j)*vec.at(i-j-1);
            }
        }
        return vec.at(n);
    }
};
