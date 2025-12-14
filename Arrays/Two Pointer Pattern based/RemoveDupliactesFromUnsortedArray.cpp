//using extra space
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        set<int>st;
        vector<int>ans;
        for(int i=0; i<arr.size(); i++){
            if(st.count(arr[i])){
                continue;
            }else{
                st.insert(arr[i]);
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};