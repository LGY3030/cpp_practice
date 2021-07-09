//Solution 1
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0) return{};
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            if(i==0) res.push_back(vector<int>(1,1));
            else if(i==1) res.push_back(vector<int>(2,1));
            else{
                vector<int> vec;
                vec.push_back(1);
                for(int j=1;j<i;j++){
                    int tmp=res[i-1][j-1]+res[i-1][j];
                    vec.push_back(tmp);
                }
                vec.push_back(1);
                res.push_back(vec);
            }
        }
        return res;   
    }
};


//Solution 2
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            res.push_back(vector<int>(i+1,1));
            for(int j=1;j<i;j++) res[i][j]=res[i-1][j-1]+res[i-1][j];
        }
        return res;   
    }
};

//Solution 3
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=1; i<=numRows; i++){
            vector<int> vec;
            for(int j=0; j<i; j++){
                if(j==0 || j==i-1) vec.push_back(1);
                else vec.push_back(res[i-2][j-1]+res[i-2][j]);
            }
            res.push_back(vec);
        }
        return res;
    }
};
