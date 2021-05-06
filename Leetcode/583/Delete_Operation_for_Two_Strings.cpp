class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> vec(word1.size()+1, vector<int> (word2.size()+1, 0));
        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<=word2.size(); j++){
                if(word1[i-1]==word2[j-1]) vec[i][j]=vec[i-1][j-1]+1;
                else vec[i][j]=max(vec[i][j-1], vec[i-1][j]);
            }
        }
        return word1.size()+word2.size()-2*vec[word1.size()][word2.size()];
    }
};
