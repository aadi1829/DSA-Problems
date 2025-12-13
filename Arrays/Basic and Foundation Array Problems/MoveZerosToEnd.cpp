//Brute force approach using Additional space
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>ans;
        int cnt = 0;
        for(auto it:nums){
            if(it != 0){
                ans.push_back(it);
            }else{
                cnt++;
            }
        }
        
        while(cnt--){
            ans.push_back(0);
        }

        nums = ans;
    }
};

//optimal approach using two pointer
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};