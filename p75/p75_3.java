public class p75_3 {
    public void sortColors(int[] nums) {
        int j=0,k=nums.length-1;
        for(int i=0;i<=k;i++)
            if(nums[i]==0)
            {
                nums[i]=nums[j];
                nums[j]=0;
                j++;
            }
            else
            if(nums[i]==2)
            {
                nums[i]=nums[k];
                nums[k]=2;
                i--;
                k--;
            }
    }
}