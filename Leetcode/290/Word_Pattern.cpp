//Solution 1
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

//Solution 2
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string pattern_simple="";
        unordered_map<char, int> umap;
        int count=0;
        for(auto&i:pattern){
            if(umap.find(i)==umap.end()){ 
                umap[i]=count;
                count++;
            }
            pattern_simple+=(umap[i]+'a');
        }
        unordered_map<string, int> umap2;
        string pattern_s="";
        count=0;
        string temp="";
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                if(temp.length()>0){
                    if(umap2.find(temp)==umap2.end()){
                        umap2[temp]=count;
                        count++;
                    }
                    pattern_s+=(umap2[temp]+'a');
                }
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        if(temp.length()>0){
            if(umap2.find(temp)==umap2.end()){
                umap2[temp]=count;
                count++;
            }
            pattern_s+=(umap2[temp]+'a');
        }
        return pattern_s==pattern_simple;
    }
};
