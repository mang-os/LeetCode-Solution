class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      int n=gain.size();
      int highest=0,currentSum=0;
      for(int i=0;i<n;i++){
        currentSum+=gain[i];
        highest=max(highest,currentSum);
      }
      return highest;
    }
};