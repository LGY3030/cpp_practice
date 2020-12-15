//Solution 1, Exceed time limit 
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int flag = 0;
        map<int, int> umap;
        for(int i=3; i<=n; i+=2){
            flag = 0;
            for(auto get: umap){
                if(get.second*get.second>i) break;
                if(i%get.second == 0){
                    cout<<get.second;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) umap[i] = i;
        }
        return umap.find(n)!=umap.end()? umap.size():umap.size()+1;
    }
};

//Solution 2
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int sum = 1;
        vector<int> vec(n, 0);
        int mid = sqrt(n);
        for(int i=3; i<n ;i+=2){
            if(vec.at(i) == 0){
                sum++;
                if(i>mid) continue;
                for(int j=i*i; j<n; j+=i*2){//avoid even number
                    vec.at(j) = 1;
                }
            }
        }
        return sum;
    }
    
};
