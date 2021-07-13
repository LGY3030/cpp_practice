//Solution 1, Time Exceeded
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size()<=1) return vector<int>(1);
        vector<int> vec(T.size());
        for(int i=0;i<T.size()-1;i++){
            for(int j=i+1;j<T.size();j++){
                if(T[j]>T[i]){
                    vec[i]=j-i;
                    break;
                }
                vec[i]=0;
            }
        }
        return vec;
    }
};

//Solution 2, struct
struct twonum{
    int tem;
    int count;
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size()<=1) return vector<int>(1);
        vector<int> vec(T.size());
        stack<twonum> sta;
        twonum twon;
        for(int i=T.size()-1;i>=0;i--){
            int cnt=0;
            int flag=0;
            while(sta.size()!=0){
                if(T[i]>=sta.top().tem){
                    cnt+=sta.top().count;
                    sta.pop();
                }
                else{
                    cnt++;
                    flag=1;
                    break;
                }
            }
            twon.tem=T[i];
            if(flag==0) twon.count=0;
            else twon.count=cnt;
            sta.push(twon);
            vec[i]=twon.count;
        }
        return vec;
    }
};


//Solution 3, pair
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size()<=1) return vector<int>(1);
        vector<int> vec(T.size());
        stack<pair<int, int>> sta;
        for(int i=T.size()-1;i>=0;i--){
            int cnt=0;
            int flag=0;
            while(sta.size()!=0){
                if(T[i]>=sta.top().first){
                    cnt+=sta.top().second;
                    sta.pop();
                }
                else{
                    cnt++;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                sta.push(make_pair(T[i], 0));
                vec[i]=0;
            }
            else{
                sta.push(make_pair(T[i], cnt));
                vec[i]=cnt;
            }
        }
        return vec;
    }
};

//Solution 4
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> sta;
        for(int i=0; i<temperatures.size(); i++){
            while(!sta.empty()){
                if(temperatures[i]>sta.top().first){
                    res[sta.top().second]=i-sta.top().second;
                    sta.pop();
                }
                else break;
            }
            sta.push({temperatures[i], i});
        }
        return res;
    }
};
