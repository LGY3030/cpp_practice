//Solution 1, Brute Method, time exceeded
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=-1;
        for(int i=0; i<height.size(); i++){
            for(int j=0; j<height.size(); j++){
                res = max(res, min(height[i], height[j])*abs(i-j));
            }
        }
        return res;
    }
};


//Solution 2
class Solution {
public:
    int maxArea(vector<int>& height) {
        int first=0;
        int second=height.size()-1;
        int res=-1;
        while(first<second){
            res=max(res, min(height[first], height[second])*(second-first));
            if(height[first]<height[second]) first++;
            else second--;
        }
        return res;
    }
};
