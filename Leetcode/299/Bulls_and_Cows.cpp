class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0;
        int b=0;
        unordered_map<char, int> umap;
        vector<char> tmp;
        for(auto&i:secret){
            umap[i]++;
            tmp.push_back(i);
        }
        for(int i=0;i<guess.size();i++){
            if(umap.find(guess[i])!=umap.end()){
                if(umap[guess[i]]!=0){
                    b++;
                    umap[guess[i]]--;
                }
            }
            if(tmp[i]==guess[i]) a++;
        }
        b-=a;
        string res=to_string(a)+"A"+to_string(b)+"B";
        return res;
    }
};
