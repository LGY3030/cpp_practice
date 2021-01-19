//Solution 1, O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.size()<=1) return nums.size();
        vector<int> current;
        vector<int> count;
        for(auto&i:nums){
        	int tmp=0;
			for(int j=0;j<current.size();j++){
				if(i>current[j]){
					tmp=max(tmp,count[j]);	
				}
			}
			current.push_back(i);
			count.push_back(tmp+1);
		}
		int res=0;
		for(auto&i:count){
			res=max(res,i);
		}
		return res;
    }
};



//Solution 2, reduce space
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.size()<=1) return nums.size();
        vector<int> count;
        for(auto&i:nums){
        	int tmp=0;
			for(int j=0;j<count.size();j++){
				if(i>nums[j]){
					tmp=max(tmp,count[j]);	
				}
			}
			count.push_back(tmp+1);
		}
		int res=0;
		for(auto&i:count){
			res=max(res,i);
		}
		return res;
    }
};


//Solution 3, with binary search, O(nlogn)
class Solution {
public:
    int searchindex(vector<int>& current, int num){
        int first=0;
        int second=current.size()-1;
        while(first<second){
            int mid=(first+second)/2;
            if(current[mid]==num) return -1;
            if(current[mid]>num) second=mid;
            else first=mid+1;
        }
        return first;
        
    }
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.size()<=1) return nums.size();
        vector<int> current;
        for(auto&i:nums){
            if(current.size()==0){
                current.push_back(i);
                continue;
            }
        	if(i>current[current.size()-1]){
                current.push_back(i);
                continue;
            }
            int tmp=searchindex(current, i);
            if(tmp!=-1) current[tmp]=i;
		}

		return current.size();
    }
};


//Solution 4, use built-in function->lower_bound(itr,itr,num)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.size()<=1) return nums.size();
        vector<int> current;
        for(auto&i:nums){
            auto it=lower_bound(current.begin(),current.end(),i);
            if(it!=current.end()){
                *it=i;
            }
            else{
                current.push_back(i);
            }
        }
		return current.size();
    }
};
