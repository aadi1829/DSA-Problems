class Solution {
public:
    void solve(vector<int>&nums,int target,vector<int>&output,vector<vector<int>>&ans,int sum,int index){
        if(sum == target){
            ans.push_back(output);
            return;
        }
        if(sum > target) return;

        for(int i=index; i<nums.size(); i++){
            output.push_back(nums[i]);
            solve(nums,target,output,ans,sum+nums[i],i); //maine yha glti ki thi, i ki jgh index ko hi pass kr rha tha
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        int sum = 0;
        int index = 0;
        solve(nums,target,output,ans,sum,index);
        return ans;
    }
};