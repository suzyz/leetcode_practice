import java.util.*;
//import java.lang.*;

public class p11 {
    public static int maxArea(int[] height) {
 		int l=0,r=height.length-1,ans=0;

 		while(l<r)
 		{
 			int h=Math.min(height[l],height[r]);

 			ans=Math.max(ans,h*(r-l));

 			while(l<r && height[l]<=h) l++;
 			while(l<r && height[r]<=h) r--;
 		}

 		return ans;
    }

    public static void main(String[] args)
    {
    	int[] height = {2,3,4,5,18,17,6};
    	int ans = maxArea(height);
    	System.out.println("max:"+ans);
    }
}