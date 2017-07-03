import java.util.*;

public class p47 {
    public List<List<Integer>> permuteUnique(int[] nums) {
        int n=nums.length;
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(n==0) return ans;

        Arrays.sort(nums);
        int m=0;
        for(int i=1;i<n;i++)
        	if(nums[i]!=nums[m])
        	{
        		m++;
        		nums[m]=nums[i];
        	}
        int[] freq = new int[m];
    }
}
