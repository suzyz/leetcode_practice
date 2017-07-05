public class p41 {
    public static int firstMissingPositive(int[] nums) {
        int n=nums.length;
        int idx=0;
        for(int i=0;i<n;i++)
        	if(nums[i]>0)
        	{
        		nums[idx]=nums[i];
        		idx++;
        	}
        
        if(idx==0) return 1;
        n=idx;

        int tmp=0;
        for(int i=0;i<n;i++)
        {
            tmp=Math.abs(nums[i]);
            if(tmp<=n && nums[tmp-1]>0) nums[tmp-1]=-nums[tmp-1];
        }
        
        for(int i=0;i<n;i++)
            if(nums[i]>0) return i+1;
        return n+1;
    }
    public static void main(String[] args) {
        int[] nums={1,2,3};
        System.out.println("ans:"+firstMissingPositive(nums));
    }
}