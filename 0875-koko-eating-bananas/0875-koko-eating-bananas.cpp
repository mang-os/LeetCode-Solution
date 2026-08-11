class Solution {
public:
    int findMax(vector<int> & piles){
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    long long calculateTotalHours(vector<int> & piles ,int hourly){
        long long  totalHr=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            totalHr += ceil((double)piles[i]/(double)hourly);
        }
        return totalHr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1 , high =findMax(piles);
        while(low<=high){
            int mid = (low+high)/2;
            long long  totalHr=calculateTotalHours(piles,mid);
            if(totalHr<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};