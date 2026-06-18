class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        int l = 0 , r = n-1, maxl = 0 , maxr = 0 , water = 0;

        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] >= maxl){
                    maxl = height[l];
                }else{
                    water += maxl - height[l];
                }
                l++;
            }else{
                if(height[l] >= height[r]){
                if(height[r] >= maxr){
                    maxr = height[r];
                }else{
                    water += maxr - height[r];
                }
                r--;
            }
        }
        }
        return water;
    }
};
