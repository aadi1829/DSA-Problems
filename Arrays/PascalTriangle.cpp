// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0; i<numRows; i++){
            vector<int>temp(i+1);
            temp[0] = 1; //stating mai hi ek value insert krli, qki pascal mai hoti hai

            for(int j=1; j<=i; j++){
                if(j != i){//ye if condition first Index and Last index ke alawa sbhi index ke liye chlegi
                    temp[j] = ans[i-1][j-1] + ans[i-1][j];
                }else{
                    temp[j] = 1; //ye wo value jo array ke last mai insert hoti hai
                }
            }

            ans.push_back(temp);

        }

        return ans;
    }
};