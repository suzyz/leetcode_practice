import java.util.*;

public class p18 {
    public static List<List<Integer>> fourSum(int[] nums, int target) {
        int n=nums.length;
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(n<4) return ans;
        
        Arrays.sort(nums);

        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;

            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[n-1]+nums[n-2]<target) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;

                int lo=j+1,hi=n-1,tmp=nums[i]+nums[j];
                while(lo<hi)
                {
                    int sum=tmp+nums[lo]+nums[hi];
                    if(sum==target)
                    {
                        ans.add(Arrays.asList(nums[i],nums[j],nums[lo],nums[hi]));
                        while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                        lo++; hi--;
                    }
                    else
                    if(sum<target) lo++;
                    else hi--;
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {1,0,-1,0,-2,2};
        List<List<Integer>> ans =fourSum(nums,0);
        for(int i=0;i<ans.size();i++)
        {
            System.out.println("i:"+i);
            for(int j=0;j<ans.get(i).size();j++)
                System.out.println("j:"+j+" ans[i][j]:"+ans.get(i).get(j));
        }
    }
}