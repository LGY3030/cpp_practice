//Using dynamic programming
//ex: 3��node, ����Ĥ@�ӷ�root, ����0��, �k��2��, 0�Ӫ��զX���W2�Ӫ��զX�N�O�o�ر��p���զX, �A��ĤG�ӷ�root, �H������
//�]�����Φ����䪺node�@�w�|��쥻��, �ҥH�����ADP�������� 
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
