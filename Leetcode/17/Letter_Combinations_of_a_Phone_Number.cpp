//Solution 1
class Solution {
private:
    void getcom(vector<string> &res, string digits, string temp){
        if(digits.length()==0){
            if(temp.length()!=0) res.push_back(temp); 
        }
        else{
            switch(digits[0]){
                case '2':
                    getcom(res, digits.substr(1), temp+'a');
                    getcom(res, digits.substr(1), temp+'b');
                    getcom(res, digits.substr(1), temp+'c');
                    break;
                case '3':
                    getcom(res, digits.substr(1), temp+'d');
                    getcom(res, digits.substr(1), temp+'e');
                    getcom(res, digits.substr(1), temp+'f');
                    break;
                case '4':
                    getcom(res, digits.substr(1), temp+'g');
                    getcom(res, digits.substr(1), temp+'h');
                    getcom(res, digits.substr(1), temp+'i');
                    break;
                case '5':
                    getcom(res, digits.substr(1), temp+'j');
                    getcom(res, digits.substr(1), temp+'k');
                    getcom(res, digits.substr(1), temp+'l');
                    break;
                case '6':
                    getcom(res, digits.substr(1), temp+'m');
                    getcom(res, digits.substr(1), temp+'n');
                    getcom(res, digits.substr(1), temp+'o');
                    break;
                case '7':
                    getcom(res, digits.substr(1), temp+'p');
                    getcom(res, digits.substr(1), temp+'q');
                    getcom(res, digits.substr(1), temp+'r');
                    getcom(res, digits.substr(1), temp+'s');
                    break;
                case '8':
                    getcom(res, digits.substr(1), temp+'t');
                    getcom(res, digits.substr(1), temp+'u');
                    getcom(res, digits.substr(1), temp+'v');
                    break;
                case '9':
                    getcom(res, digits.substr(1), temp+'w');
                    getcom(res, digits.substr(1), temp+'x');
                    getcom(res, digits.substr(1), temp+'y');
                    getcom(res, digits.substr(1), temp+'z');
                    break;
            }
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        getcom(res, digits, "");
        return res;
    }
};

//Solution 2
class Solution {
private:
    void getcom(vector<string> &res, string digits, string temp, vector<string>& vec){
        if(digits.length()==0){
            if(temp.length()!=0) res.push_back(temp); 
        }
        else{
            for(auto& i:vec[digits[0]-'0'-2]){
                getcom(res, digits.substr(1), temp+i, vec);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> vec={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        getcom(res, digits, "", vec);
        return res;
    }
};

//Solution 3
class Solution {
private:
    vector<string> number={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void bk(vector<string>& res, string& digits, int idx, string str){
        if(idx==digits.length()){
            res.push_back(str);
            return;
        }
        for(int i=0; i<number[digits[idx]-'0'-2].length(); i++){
            bk(res, digits, idx+1, str+number[digits[idx]-'0'-2][i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string> res;
        bk(res, digits, 0, "");
        return res;
    }
};
