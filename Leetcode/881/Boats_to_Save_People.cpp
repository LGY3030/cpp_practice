class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int slow=0;
        int fast=people.size()-1;
        int res=0;
        while(slow<=fast){
            if(people[fast]+people[slow]>limit) fast--;
            else{
                fast--;
                slow++;
            }
            res++;
        }
        return res;
    }
};
