public class p55 {
    public static boolean canJump(int[] nums) {
        int n=nums.length;
    	int max=0;
        for(int i=0;i<n;i++)
        {
        	if(i>max) return false;
        	int tmp=i+nums[i];
        	max=tmp>max ? tmp:max;
        	if(max>=n-1) return true;
        }
        System.out.println(max+" "+n);
        return (max>=n-1);
    }
    public static void main(String[] args) {
    	int[] nums={0};
    	System.out.println(canJump(nums));
    }
}
