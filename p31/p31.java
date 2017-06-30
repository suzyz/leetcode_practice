public class p31 {
	 public static void traverseSort(int[] nums,int begin,int end)
	 {
       	for(int i=begin;i<=(end+begin)/2;i++)
       	{
       		int j=end+begin-i;
       		int tmp=nums[i]; nums[i]=nums[j]; nums[j]=tmp;
       	}
	 }
    public void nextPermutation(int[] nums) 
    {
		    int n=nums.length;

       	for(int i=n-1;i>0;i--)
       		if(nums[i-1]<nums[i])
       		{
         			int j=n-1;
         			while(j>i && nums[j]<=nums[i-1]) j--;

         			int tmp=nums[i-1]; nums[i-1]=nums[j]; nums[j]=tmp;
         			traverseSort(nums,i,n-1);
         			return;
       		}

       	traverseSort(nums,0,n-1);
    }
}