class Solution {
public:
    bool isVowel(char c){
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        }
    int maxVowels(string s, int k) {
        int count=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        int ans=count;
        for(int right=k;right<s.size();right++){
            if(isVowel(s[right-k])){
                count--;
            }
            if(isVowel(s[right])){
                count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};