//Solution 1, Time limit exceeded
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int result = 0;
        for(int i=0; i<s.length()-1; i++){
            vector<int> vec(256, -2);
            res = 0;
            for(int j=i; j<s.length(); j++){
                if(vec.at(s[j])>-1){
                    break;
                }
                vec.at(s[j]) = i;
                res++;
            }
            result = max(res, result);
        }
        return max(1, result);
    }
};

//Solution 2 
class Solution {
	public:
	    int lengthOfLongestSubstring(string s) {
	        unordered_map<char, int> umap;
	        int res = 0;
	        int start = 0;
	        for(int i=0; i<s.length(); i++){
	            if(umap.find(s[i])!=umap.end()){
	                if(umap[s[i]]>=start){
	                    int tmp = i - start;
	                    if(tmp>res) res = tmp;
	                    start = umap[s[i]] + 1;
	                }
	                umap[s[i]] = i;
	            }
	            else{
	                umap[s[i]] = i;
	            }
	            if(i == s.length() - 1){
	                int tmp = i - start + 1;
	                if(tmp>res) res = tmp;
	            }
	        }
	        return res;
	    }
};

//Solution 3
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(256,-2);
        int start = -1;
        int res = 0;
        for(int i=0; i<s.length(); i++){
            if(vec.at(s[i]) > start){
                start = vec.at(s[i]);
            }
            vec.at(s[i]) = i;
            res = max(res, i-start);
        }
        return res;
    }
};

//Solution 4
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int res=0;
        int slow=0;
        for(int i=0; i<s.length(); i++){
            if(umap.find(s[i])!=umap.end() && umap[s[i]]>=slow) slow=umap[s[i]]+1;
            umap[s[i]]=i;
            res=max(res, i-slow+1);
        }
        return res;
    }
};
