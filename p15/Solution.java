
import java.util.*;

public class Solution {
    public static List<List<Integer>> threeSum(int[] nums) {
       Arrays.sort(nums);

       List<List<Integer>> res = new LinkedList<>();

       for(int i=0;i<nums.length-2;i++)
       if(i==0 || (i>0 && nums[i]!=nums[i-1]))
       {
       		int lo=i+1,hi=nums.length-1,sum=0-nums[i];
            
       		while(lo<hi)
       		{
       			if(nums[lo]+nums[hi]==sum)
       			{
       				res.add(Arrays.asList(nums[i],nums[lo],nums[hi]));
       				while(lo<hi && nums[lo+1]==nums[lo]) lo++;
       				while(lo<hi && nums[hi-1]==nums[hi]) hi--;
                              lo++; hi--;
       			}
       			else
       			if(nums[lo]+nums[hi]<sum) lo++;
       			else
       				hi--;
       		}
                  
       }
       return res;
    }

    public static void main(String[] args)
    {
      int[] nums = {-1,0,1,2,-1,-4};
      System.out.println(nums[0]);
      System.out.println("abc");
      List<List<Integer>> ans=threeSum(nums);

      for(int i=0;i<ans.size();i++)
      {
            System.out.println(i+":");
            for(int j=0;j<3;j++)
             System.out.println(ans.get(i).get(j));
      }
    }
}