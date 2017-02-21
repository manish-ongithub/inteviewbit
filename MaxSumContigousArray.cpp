/*

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.
*/

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int max(int a,int b)
 {
     if (a>b)
        return a;
     else
        return b;
 }
int maxSubArray(const int* A, int n1) {
    
    
    if(n1 ==1)
    return A[0];
    
    int m =n1/2;
    int left_mss = maxSubArray(A,m);
    int right_mss = maxSubArray(A+m,n1-m);
    int leftSum = -65535 ;
    int rightSum = -65535 ,sum = 0;
    
    int i=0;
    for(i=m;i<n1;i++)
    {
        sum += A[i];
        rightSum = max(rightSum,sum);
    }
    sum = 0;
    for(i=m-1;i>=0;i--)
    {
        sum += A[i];
        leftSum = max(leftSum,sum);
    }
    int ans = max(left_mss,right_mss);
    return max(ans,leftSum+rightSum);
}
