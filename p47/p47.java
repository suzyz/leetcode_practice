import java.util.*;

public class p47 {
    public void dfs(int cur,int n,boolean[] used,int[] permutation,int[] nums,List<List<Integer>> ans)
    {
        if(cur==n)
        {
            List<Integer> tmp = new ArrayList<Integer>();
            for(int i=0;i<n;i++) tmp.add(permutation[i]);
            ans.add(tmp);
            return;
        }
        for(int i=0;i<n;i++)
            if(!used[i])
            {
                if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
                used[i]=true;
                permutation[cur]=nums[i];
                dfs(cur+1,n,used,permutation,nums,ans);
                used[i]=false;
            }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        int n=nums.length;
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(n==0) return ans;

        Arrays.sort(nums);
        dfs(0,n,new boolean[n],new int[n],nums,ans);
        return ans;
    }
}
