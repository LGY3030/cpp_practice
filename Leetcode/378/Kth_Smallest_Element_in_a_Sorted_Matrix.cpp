//Solution 1
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp=[](int a, int b){
            return a>b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for(auto&i:matrix){
            for(auto&j:i) pq.push(j);
        }
        for(int i=0; i<k-1; i++) pq.pop();
        return pq.top();
    }
};

//Solution 2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp=[](int a, int b){
            return a<b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for(auto&i:matrix){
            for(auto&j:i){
                pq.push(j);
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }
};

//Solution 3
class Solution {
private:
    struct cmp{
        bool operator()(int a, int b){
            return a<b;
        }  
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, cmp> pq;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(pq.size()<k) pq.push(matrix[i][j]);
                else if(pq.top()>matrix[i][j]){
                    pq.push(matrix[i][j]);
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};

//Solution 4
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        int column=matrix[0].size();
        int left=matrix[0][0];
        int right=matrix[row-1][column-1];
        while(left<right){
            int mid=(left+right)/2;
            int count=0;
            for(int i=0; i<row; i++){
                count=count+(upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin());
            }
            if(count<k) left=mid+1;
            else right=mid;
        }
        return right;
    }
};
