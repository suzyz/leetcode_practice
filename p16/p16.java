import java.util.*;

public class p16 {
    public static int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        int ans = nums[0]+nums[1]+nums[n-1];

        Arrays.sort(nums);

        for(int i=0;i<n-2;i++)
        {
        	int l=i+1,r=n-1;
        	while(l<r)
	        {
	        	int tmp=nums[i]+nums[l]+nums[r];
	         	if(tmp==target) return target;
	         	if(tmp>target) r--;
	         	else l++;

	         	if(Math.abs(ans-target)>Math.abs(tmp-target)) ans=tmp;
        	}
        }
        return ans;
    }

    public static void main(String[] args)
    {
    	int[] nums = {1,6,9,14,16,70};
    	int target = 81;
    	int ans = threeSumClosest(nums,target);
    	System.out.println("ans:"+ans);
    }
}