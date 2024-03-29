//Solution 1
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(), digits.end());
        int carry=1;
        for(int i=0; i<digits.size(); i++){  
            if(digits[i]+carry==10) {
                digits[i]=0;
                carry=1;
            }
            else{
                digits[i]=digits[i]+carry;
                carry=0;
                break;
            }
        }
        if(carry==1) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        
        return digits;
    }
};



//Solution 2 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]==9) digits[i]=0;
            else{
                digits[i]++;
                return digits;
            }
        }
        digits[0]=1;
        digits.push_back(0);
        return digits;
    }
};


//Solution 3
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]==9) digits[i]=0;
            else{
                digits[i]++;
                return digits;
            }
        }
        digits[0]=0;
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

//Solution 4
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1; i>=0; i--){
            int temp=digits[i];
            digits[i]=(temp+carry)%10;
            carry=(temp+carry)/10;
        }
        if(carry) digits.insert(digits.begin(), carry);
        return digits;
    }
};

//Solution 5
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            int tmp = digits[i] + carry;
            carry = tmp / 10;
            res.insert(res.begin(), tmp % 10);
        }
        if(carry){
            res.insert(res.begin(), carry);
        }
        return res;
    }
};
