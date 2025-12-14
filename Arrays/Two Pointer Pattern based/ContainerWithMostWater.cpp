//Optimal Approach using Two Pointers
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = INT_MIN;
        int i=0,j=height.size()-1;
        while(i<j){
            int minHeight = min(height[i],height[j]);
            int area = minHeight*(j-i);
            maxi = max(maxi,area);

            if(height[i] <= height[j]) i++;
            else j--;
        }
        return maxi;
    }
};

//Brute Forece Approach using Two For Loop
class Solution {
public://brute force
    int maxArea(vector<int>& height) {
        int maxi = INT_MIN;
        for(int i=0; i<height.size(); i++){
            for(int j=i+1; j<height.size(); j++){
                int mini = min(height[i],height[j]);
                maxi = max(maxi,(mini*(j-i)));
            }
        }
        return maxi;
    }
};