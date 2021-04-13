//Solution 1
class Solution {
public:
    string intToRoman(int num) {
        string res="";
        int count=0;
        vector<string> vec={"I", "V", "X", "L", "C", "D", "M", "0"};
        while(num!=0){
            int tmp=(num%10);
            if(tmp==9) res=vec[count]+vec[count+2]+res;
            else if(tmp==4) res=vec[count]+vec[count+1]+res;
            else if(tmp>=5){
                for(int i=0;i<tmp-5;i++){
                    res=vec[count]+res;
                }
                res=vec[count+1]+res;
            }
            else{
                for(int i=0;i<tmp;i++){
                    res=vec[count]+res;
                }
            }
            num/=10;
            count+=2;
        }
        return res;
    }
};


//Solution 2
class Solution {
public:
    string intToRoman(int num) {
        string res="";
        vector<string> svec={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> ivec={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for(int i=0; num!=0; i++){
            while(num>=ivec[i]){
                res+=svec[i];
                num-=ivec[i];
            }
        }
        return res;
    }
};
