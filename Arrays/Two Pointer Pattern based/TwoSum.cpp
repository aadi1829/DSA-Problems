//classic Two Pointer pattern problem, but after sorting the array the indices will change, so we need to store the original indices in a hash map or a vector of pairs.

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum == target){
                return {i,j};
            }else if(sum < target) i++;
            else j--;
        }
        return {-1,-1};
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


        //IN CASE OF WHEN WE NEED TO RETURN TRUE OR FALSE
        // sort(nums.begin(),nums.end());

        // int low=0;
        // int high=nums.size()-1;

        // while(low<high){
        //     int sum=nums[low]+nums[high];

        //     if(sum == target){
        //         return {low,high};
        //     }
        //     else if(sum > target){
        //         high--;
        //     }
        //     else{
        //         low++;
        //     }
        // }
        // return {-1,-1};

        unordered_map<int,int> map;
        int num=0;
        int comp=0;
        for(int i=0; i<nums.size(); i++){
            num=nums[i];
            comp=target-num;
            if(map.find(comp)!=map.end()){
                return {map[comp],i};
            }
            map[num]=i;
        }
        return {-1,-1};
    }
};