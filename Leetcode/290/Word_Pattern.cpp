class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> umap;
        vector<string> vec;
        stringstream check1(s);
        string get;
        while(getline(check1, get, ' ')){
            vec.push_back(get);
        }
        if(pattern.length()!=vec.size()) return false;
        for(int i=0;i<pattern.length();i++){
            
            if(umap.find(pattern[i])!=umap.end()){
                if(umap[pattern[i]]!=vec.at(i)) return false;
            }
            else{
                for(auto gett:umap){
                    if(gett.second == vec.at(i)) return false;
                }
                umap[pattern[i]] = vec.at(i);
            }
        }
        return true;
    }
};
