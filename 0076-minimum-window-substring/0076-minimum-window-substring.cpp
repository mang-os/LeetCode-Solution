class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty()||t.empty()){
            return "";
        }
        vector<int>hash(256,0);
        int left=0,right=0;
        int minLen=INT_MAX;
        int startingIndex=-1;
        int count=0;
        int n=s.size(),m=t.size();

        for(int i=0;i<m;i++){
           hash[t[i]]++;
        }
        while(right<n){
            if (hash[s[right]]>0){
                count++;
            }
            hash[s[right]]--;

            while(count==m){
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    startingIndex=left;
                }
                hash[s[left]]++;
                if(hash[s[left]]>0){
                    count--;
                }
                left++;
            }
            right++;
        }
        return startingIndex==-1?"":s.substr(startingIndex,minLen);
    }
};