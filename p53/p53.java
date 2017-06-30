public class p53 {
    public int maxSubArray(int[] nums)
    {
        if(nums.length==0) return 0;
        int maxEndingHere=nums[0],maxSoFar=nums[0];

        for(int i=1;i<nums.length;i++)
        {
            maxEndingHere = nums[i]>maxEndingHere+nums[i] ? nums[i]:maxEndingHere+nums[i];
            maxSoFar = maxSoFar>maxEndingHere ? maxSoFar:maxEndingHere;
        }
        
        return maxSoFar;
    }

    public int maxSubArray1(int[] nums) {
        int n = nums.length;
        if(n==0) return 0;
        int sum,minsum,ans;
        sum=ans=nums[0];
        if(nums[0]<0) minsum=nums[0];
        else minsum=0;
        for(int i=1;i<n;i++)
        {
            sum+=nums[i];
            if(sum-minsum>ans) ans=sum-minsum;
            if(sum<minsum) minsum=sum;
        }

        return ans;
    }
}