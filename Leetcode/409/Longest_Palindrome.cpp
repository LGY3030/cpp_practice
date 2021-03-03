class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> umap;
        int res=0;
        int flag=0;
        for(auto&i:s) umap[i]++;
        for(auto&i:umap){
            res+=((i.second/2)*2);
            if(i.second%2==1) flag=1;
        }
        if(flag==1) res++;
        return res;
    }
};
