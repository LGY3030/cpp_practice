//Solution 1
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> vec(num1.length()+num2.length());
        string res="";
        for(int i=num2.length()-1;i>=0;i--){
            for(int j=num1.length()-1;j>=0;j--){
                int index=num2.length()-i+num1.length()-j-2;
                int tmp=(num2[i]-'0')*(num1[j]-'0');
                while(tmp>0){
                    vec[index]+=tmp%10;
                    tmp/=10;
                    if(vec[index]>=10){
                        tmp+=vec[index]/10;
                        vec[index]%=10;
                    }
                    index++;
                }
            }
        }
        int flag=0;
        for(int i=vec.size()-1;i>=0;i--){
            if(vec[i]!=0) flag=1;
            if(flag==1){
                char tmp=vec[i]+'0';
                res+=tmp;
            }
        }
        if(flag==0) return "0";
        return res;
    }
};


//Solution 2
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.length()+num2.length(), '0');
        for(int i=num1.length()-1; i>=0; i--){
            int carry=0;
            for(int j=num2.length()-1; j>=0; j--){
                int tmp=(sum[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry;
                sum[i+j+1]=tmp%10+'0';
                carry=tmp/10;
            }
            sum[i]+=carry;
        }
        int count=0;
        while(count<sum.length()){
            if(sum[count]=='0') count++;
            else break;
        }
        if(count==sum.length()) return "0";
        return sum.substr(count);
    }
};
