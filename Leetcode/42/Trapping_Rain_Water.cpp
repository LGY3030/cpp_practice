class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        vector<int> left(height.size());
        vector<int> right(height.size());
        int leftmax=0;
        int rightmax=0;
        for(int i=1; i<height.size(); i++){
            leftmax=max(leftmax, height[i-1]);
            left[i]=leftmax;
            rightmax=max(rightmax, height[height.size()-i]);
            right[height.size()-1-i]=rightmax;
        }
        for(int i=1; i<height.size()-1; i++){
            if(left[i]<=height[i] || right[i]<=height[i]) continue;
            res+=min(left[i], right[i])-height[i];
        }
        return res;
    }
};
