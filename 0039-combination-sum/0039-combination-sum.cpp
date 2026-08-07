class Solution {
public:
    void solve(int idx,int target,vector<int>&candidates,vector<int>&path,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(path);
            return;
        }
        if(idx==candidates.size()){
            return;
        }
        if(candidates[idx]<=target){
            //Do 
            path.push_back(candidates[idx]);
            //Explore
            solve(idx,target-candidates[idx],candidates,path,ans);
            //Undo
            path.pop_back();
        }
         solve(idx+1,target,candidates,path,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>path;
        solve(0,target,candidates,path,ans);

        return ans;
    }
};