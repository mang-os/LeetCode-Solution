class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;

        vector<int> temp(k);

        //Storing the value in Temp
        for (int i=0;i<k;i++){
            temp[i]=nums[n-k+i];
        }
        //Shift Remaining Element to Right 
        for(int i=n-k-1;i>=0;i--){
            nums[i+k]=nums[i];
        }
        //Putting the Temp Values in the Front 
        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
};