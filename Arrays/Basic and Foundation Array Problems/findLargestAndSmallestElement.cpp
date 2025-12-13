//Largest and Smallest Element in an Array
class Solution {
  public:
    vector<int> largest(vector<int> &arr) {
        int num = INT_MIN;
        int val = INT_MAX;
        for(auto &it:arr){
            num = max(num,it);
            val = min(val,it);
        }
        return {num,val};
    }
};


