
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        int len=len1+len2;
        printf("len:%d\n",len );
        printf("res1:%f res2:%f\n",getkth(nums1,0,len1,nums2,0,len2,len/2),getkth(nums1,0,len1,nums2,0,len2,len/2+1));
        if((len&1)==0)
        	return (double)(getkth(nums1,0,len1,nums2,0,len2,len/2)+getkth(nums1,0,len1,nums2,0,len2,len/2+1))/2;
        else
        	return getkth(nums1,0,len1,nums2,0,len2,len/2+1);
    }

    double getkth(vector<int>& nums1,int st1,int len1,vector<int>& nums2,int st2,int len2,int k)
    {
        printf("st1:%d len1:%d st2:%d len2:%d k:%d\n",st1,len1,st2,len2,k);
    	if(len1>len2) return getkth(nums2,st2,len2,nums1,st1,len1,k);
    	if(len1==0) return nums2[st2+k-1];
    	if(k==1) return min(nums1[st1],nums2[st2]);

    	int a=min(k/2,len1),b=min(k/2,len2);
        printf("a:%d b:%d\n",a,b);
    	if(nums1[st1+a-1]<nums2[st2+b-1])
    		return getkth(nums1,st1+a,len1-a,nums2,st2,len2,k-a);
    	else
    		return getkth(nums1,st1,len1,nums2,st2+b,len2-b,k-b);
    }
};

int main(int argv,char ** args)
{
	  int array1[]={1,3};
	  int array2[]={2,6,9,10};
	  vector<int> nums1(array1,array1+2);
	  vector<int> nums2(array2,array2+4);
          for(int i=0;i<2;i++) printf("%d ", nums1[i]);
          printf("\n");
          for(int i=0;i<4;i++) printf("%d ", nums2[i]);
          printf("\n");

	  Solution s;

	  printf("The median: %f\n",s.findMedianSortedArrays(nums1,nums2));

	  return 0;
}
