public class p75 {
    public void sortColors(int[] nums) {
        int n=nums.length;
        int ones=0,twos=0;
        for(int i=0;i<n;i++)
            if(nums[i]==1) ones++;
            else
            if(nums[i]==2) twos++;
        
        for(int i=0;i<n-ones-twos;i++) nums[i]=0;
        for(int i=n-ones-twos;i<n-twos;i++) nums[i]=1;
        for(int i=n-twos;i<n;i++) nums[i]=2;
    }
}