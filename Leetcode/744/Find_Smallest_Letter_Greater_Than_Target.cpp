//Solution 1
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res=letters[0];
        for(auto&i:letters){
            if(i>target){
                res=i;
                break;
            }
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start=0;
        int end=letters.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(letters[mid]<=target) start=mid+1;
            else end=mid-1;
        }
        if(start==letters.size()) return letters[0];
        return letters[start];
    }
};
