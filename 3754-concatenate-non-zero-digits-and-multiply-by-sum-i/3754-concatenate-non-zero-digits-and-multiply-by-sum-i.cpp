class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum=0;
        string numStr="";
        while(n>0){
            int digit=n%10;
            sum+=digit;

            if(digit!=0){
                numStr+=to_string(digit);
            }
            n/=10;
        }
        if(numStr.empty()){
            return 0;
        }
        reverse(numStr.begin(),numStr.end());

        long long nonZeroNum=stoll(numStr);

        return nonZeroNum*sum;
    }
};