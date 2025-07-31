class Solution {
public:
    void solve(vector<int>&nums,int index,vector<vector<int>>&ans){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,bool>visited;
        for(int i=index;i<nums.size();i++){
            if(visited.find(nums[i]) != visited.end()) continue;

            visited[nums[i]]=true;
            swap(nums[i],nums[index]);
            solve(nums,index+1,ans); //yha maine glti ki thi index+1 ki jgh i+1 pass kr rha tha
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int index = 0;
        solve(nums,index,ans);
        return ans;
    }
};