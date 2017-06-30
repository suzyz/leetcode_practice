public class p33 {
    public static int search(int[] nums, int target) {
        if(nums.length==0) return -1;

        int n=nums.length;
        if(target==nums[0]) return 0;
        if(target==nums[n-1]) return n-1;

        boolean flag=true;
       	if(target>nums[0]) flag=true;
       	else flag=false;

       	int l=1,r=n-2;
       	while(l<=r)
       	{
       		int mid=(l+r)>>1;
       		if(nums[mid]==target) return mid;
       		if(flag && nums[mid]<target)
       		{
       			if(nums[mid]>=nums[0]) l=mid+1;
       			else r=mid-1;
       		}
       		else
       		if(flag && nums[mid]>target)
       		{
       			r=mid-1;
       		}
       		else
       		if(!flag && nums[mid]<target)
       		{
       			l=mid+1;
       		}
       		else
       		if(!flag && nums[mid]>target)
       		{
       			if(nums[mid]<nums[0]) r=mid-1;
       			else l=mid+1;
       		}
       	}

        return -1;
    }
    public static void main(String[] args) {
    	int[] nums = {7,8,9,10,1,2,3,4,5,6};
    	System.out.println(search(nums,1));
    }
}
