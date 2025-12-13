//brute Force Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<nums.size(); k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int>temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};

//better Solution:using hashing 
//1. loop through the array and fix the first element
//2. then use hashing to find the other two elements(two sum Problem better approach)
//3. if the sum of the other two elements is equal to the first element then insert it in the set
//4. return the set
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        for(int i=0; i<nums.size(); i++){
            int target = 0 - nums[i];
            set<int>hash;
            for(int j=i+1; j<nums.size(); j++){
                int rem = target - nums[j];
                if(hash.find(rem) != hash.end()){
                    vector<int>temp = {nums[i],nums[j],rem};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }else{
                    hash.insert(nums[j]);
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};

//optimal Solution:using two pointer
//1. sort the array
//2. loop through the array and fix the first element
//3. then use two pointer to find the other two elements(two sum Problem optimal approach)
//4. if the sum of the other two elements is equal to the first element then insert it in the ANS
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1]) continue; //skip the duplicate elements

            int target = 0 - nums[i];
            int left = i+1;
            int right = nums.size()-1;

            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    vector<int>temp = {nums[i],nums[left],nums[right]};
                    ans.push_back(temp);
                    left++;
                    while(left < right && nums[left] == nums[left-1]) left++;//skip the duplicate elements
                    right--;
                    while(right > left && nums[right] == nums[right+1]) right--;//skip the duplicate elements
                }else if(sum < target) left++;
                else right--;
            }
        }
        return ans;
    }
};