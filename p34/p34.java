public class p34 {
    public static int[] searchRange(int[] nums, int target) {
        int[] ans=new int[2];
        ans[0]=ans[1]=-1;
        if(nums.length==0) return ans;

        int n=nums.length;
        int l=0,r=n-1;
        while(l<r)
        {
        	int mid=(l+r)>>1;
        	if(nums[mid]==target) r=mid;
        	else
        	if(nums[mid]<target) l=mid+1;
        	else r=mid-1;
        }
        if(nums[l]!=target) return ans;
        ans[0]=l;

        r=n-1;
        while(l<r)
        {
        	int mid=((l+r)>>1)+1;
        	if(nums[mid]==target) l=mid;
        	else
        	if(nums[mid]<target) l=mid+1;
        	else r=mid-1;
        }
        ans[1]=r;
        return ans;
    }
    public static void main(String[] args) {
    	int[] nums = {5,5, 7, 7, 8, 8, 8,10};
    	System.out.println(searchRange(nums,10)[0]);
    	System.out.println(searchRange(nums,10)[1]);
    }
}
