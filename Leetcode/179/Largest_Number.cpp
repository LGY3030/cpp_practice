//Solution 1, Time exceeded
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i;j<nums.size()-1;j++){
                stack<int> first;
                stack<int> second;
                int tf=nums[j];
                int ts=nums[j+1];
                int tmp1;
                int tmp2;
                int flag=0;
                while(tf!=0){
                    first.push(tf%10);
                    tf/=10;
                }
                while(ts!=0){
                    second.push(ts%10);
                    ts/=10;
                }
                while(first.size()!=0 && second.size()!=0){
                    if(first.top()==second.top()){
                        first.pop();
                        second.pop();
                    }
                    else{
                        flag=1;
                        if(first.top()>second.top()){
                            int tmp=nums[j];
                            nums[j]=nums[j+1];
                            nums[j+1]=tmp;
                        }
                    }
                }
                if(flag==0){
                    if(first.size()==0){
                        int tmp=nums[j];
                        nums[j]=nums[j+1];
                        nums[j+1]=tmp;
                    }
                }
            }
        }
        string s="";
        for(int i=nums.size()-1;i>=0;i--){
            s+=to_string(nums[i]);
        }
        return s;
    }
};

//Solution 2, use string comparison, Ex:A+B>B+A
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(auto i:nums) vec.push_back(to_string(i));
        for(int i=0;i<vec.size()-1;i++){
            for(int j=0;j<vec.size()-1-i;j++){
                if(vec[j]+vec[j+1]<vec[j+1]+vec[j]){
                    string tmp=vec[j];
                    vec[j]=vec[j+1];
                    vec[j+1]=tmp;
                }
            }
        }
        string res="";
        for(auto i:vec) res+=i;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res;
    }
};


//Solution 3, use sort function and cmp parameter(lambda function)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(auto i:nums) vec.push_back(to_string(i));
        sort(vec.begin(),vec.end(),[](string &a, string &b){return a+b>b+a;});
        string res="";
        for(auto i:vec) res+=i;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res;
    }
};
