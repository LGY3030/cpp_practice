class Solution {
private:
    void bt(string s, string tmp, vector<string>& res, int count){
        if(count==3){
            if(s.length()==3 && s>="100" && s<="255") res.push_back(tmp+s);
            if(s.length()==2 && s>="10") res.push_back(tmp+s);
            if(s.length()==1) res.push_back(tmp+s);
            return;
        }
        if(s.length()>=1) bt(s.substr(1), tmp+s.substr(0,1)+'.', res, count+1);
        if(s.length()>=2 && s.substr(0,2)>="10") bt(s.substr(2), tmp+s.substr(0,2)+'.', res, count+1);
        if(s.length()>=3 && s.substr(0,3)>="100" && s.substr(0,3)<="255") bt(s.substr(3), tmp+s.substr(0,3)+'.', res, count+1);
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        bt(s, "", res, 0);
        return res;
    }
};
