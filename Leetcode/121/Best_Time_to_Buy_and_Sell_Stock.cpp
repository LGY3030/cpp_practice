//Solution 1, Brutal method, time exceeded
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                res=max(res, prices[j]-prices[i]);
            }
        }
        return res;
    }
};


//Solution 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minnum=prices[0];
        int res=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-minnum>0){
                res=max(res,prices[i]-minnum);
            }
            minnum=min(minnum,prices[i]);
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        stack<pair<int, int>> sta;
        for(int i=0; i< prices.size(); i++){
            if(sta.empty()) sta.push({prices[i], 0});
            else{
                while(!sta.empty() && sta.top().first>prices[i]){
                    sta.pop();
                }
                if(sta.empty()) sta.push({prices[i], 0});
                else{
                    res=max(res, prices[i]-sta.top().first+sta.top().second);
                    sta.push({prices[i], prices[i]-sta.top().first+sta.top().second});
                }
            }
        }
        return res;
    }
};
