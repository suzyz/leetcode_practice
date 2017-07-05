import java.util.*;

public class p45 {
    public static int jump(int[] nums) {
        int n=nums.length;
        if(n<2) return 0;
        
        int level=0,curLevelMax=0,NextLevelMax=0;
        for(int i=0;i<n;i++)
        {
            NextLevelMax=i+nums[i]>NextLevelMax ? i+nums[i]:NextLevelMax;
            if(i==curLevelMax)
            {
                curLevelMax=NextLevelMax;
                level++;
            }
        }
        return level;
    }
    public static void main(String[] args) {
        int[] nums={2,1};
        System.out.println("ans:"+jump(nums));
    }
}