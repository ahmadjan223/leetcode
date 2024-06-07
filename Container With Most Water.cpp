class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int i=0;
        int j = height.size()-1;
        while(i<j){
            int capacity = (j-i) * min(height[i],height[j]);
            maxArea = max(maxArea,capacity);
            if(height[i]>height[j]){
                j--;
            }
            //note for equal height it does'nt matter which is moved
            else{
                i++;
            }
        }
        return maxArea;
    }
};
