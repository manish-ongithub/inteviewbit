/*
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.
*/
int factorial(int n)
{
   return (n == 0)? 1 : n*factorial(n-1);
} 

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int rowCount = A.size();
    int colCount = 0;
    if(rowCount > 0)
    {
        colCount = A[0].size();
    }
    
    vector<int> lstRow;
    vector<int> lstCol;
    
    for(int r=0;r<rowCount;r++)
    {
        for(int c=0;c<colCount;c++)
        {
            if(A[r][c] == 0)
            {
                if (std::find(lstRow.begin(), lstRow.end(), r) == lstRow.end())
                {
                  lstRow.push_back(r);
                }
                if (std::find(lstCol.begin(), lstCol.end(), c) == lstCol.end())
                {
                  lstCol.push_back(c);
                }
            }
        }

    }
    for(int r=0;r<lstRow.size();r++)
    {
        int row = lstRow[r];
        for(int c = 0;c < A[row].size();c++)
            A[row][c] = 0;
    }
    for(int c=0;c<lstCol.size();c++)
    {
        int col = lstCol[c];
        for(int r = 0;r < A.size();r++)
            A[r][col] = 0;
    }
}
