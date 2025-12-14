//approach:
//1.use left and right array to store the maximum height of the left and right side of the current element
//2.then for each element find the minimum of left and right array and subtract the current element from it
//3.then add the result to the total area
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);

        for(int i=1; i<n; i++){
            left[i] = max(left[i-1],height[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1],height[i+1]);
        }

        int totalArea = 0;
        for(int i=1; i<n-1; i++){
            int mini = min(left[i],right[i]);
            int area = mini - height[i];
            if(area < 0){
                area = 0;
            }
            totalArea += area;
        }

        return totalArea;
    }
};