class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] result=new int[nums.length];
        ArrayList<Integer> list_p=new ArrayList<>();
        ArrayList<Integer> list_n=new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            if(nums[i]>=0){
                list_p.add(nums[i]);
            }else{
                list_n.add(nums[i]);
            }
        }
        int index_p=0;
        int index_n=0;
        for(int i=0;i<nums.length;i++){
            if(i%2==0){
                result[i]=list_p.get(index_p);
                index_p++;
            }else{
                result[i]=list_n.get(index_n);
                index_n++;
            }
        }
        return result;
    }
}