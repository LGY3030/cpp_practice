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
