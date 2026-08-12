class Solution {
public:
    int maxArea(vector<int>& height) {
         int n=height.size();
         int left=0,right=n-1;
         int maxi=0;
         while(left<right){
            
            int area=(right-left)*(min(height[left],height[right]));
            maxi=max(maxi,area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }   
         }
         return maxi;  
    }
     
};