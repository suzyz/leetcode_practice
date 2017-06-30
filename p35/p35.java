public class Solution {
    public int searchInsert(int[] nums, int target) {
        int n=nums.length;
        int l=0,r=n-1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(nums[mid]<target) l=mid+1;
            else
            if(nums[mid]==target) return mid;
            else r=mid;
        }
        if(nums[l]>=target) return l;
        else return n;
    }
    public int searchInsert1(int[] nums, int target) {
        int n=nums.length;
        for(int i=0;i<n;i++)
            if(nums[i]>=target) return i;
        return n;
    }
}