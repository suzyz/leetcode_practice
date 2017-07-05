public class p75_2 {
    public void sortColors(int[] nums) {
        int n=nums.length,n0=0,n1=0,n2=0;
        for(int i=0;i<n;i++)
            switch(nums[i])
            {
                case 0:
                    nums[n2]=2; nums[n1]=1; nums[n0]=0;
                    n2++; n1++; n0++;
                    break;
                case 1:
                    nums[n2]=2; nums[n1]=1;
                    n2++; n1++;
                    break;
                case 2:
                    nums[n2]=2;
                    n2++;
                    break;
            }
    }
}