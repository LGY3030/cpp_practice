//Solution 1
class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string res="";
        for(int i=a.length()-1, j=b.length()-1; i>=0||j>=0; i--, j--){
            int tmp=carry;
            if(i>=0) tmp+=(a[i]-'0');
            if(j>=0) tmp+=(b[j]-'0');
            if(tmp>=2){
                carry=1;
                char temp=tmp%2+'0';
                res=temp+res;
            }
            else{
                carry=0;
                char temp=tmp+'0';
                res=temp+res;
            }
        }
        if(carry) res='1'+res;
        return res;
    }
};

//Solution 2
class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int i=a.length()-1;
        int j=b.length()-1;
        string res="";
        while(i>=0 || j>=0 || carry==1){
            int tmp=carry;
            if(i>=0) tmp+=(a[i--]-'0');
            if(j>=0) tmp+=(b[j--]-'0');
            res=char(tmp%2+'0')+res;
            carry=tmp/2;
        }
        return res;
    }
};
