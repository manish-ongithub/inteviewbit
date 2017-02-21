/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.
*/
vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int size = A.size();
    int carry = 0;
    for(int i=size-1;i>=0;i--)
    {
        if(i == size -1)
        {
            int val = A[i];
            int result = val+1;
            
            if(result > 9)
            {
                carry = result / 10;
                int remain = result % 10;
             A[i] = remain;    
                
            }
            else 
            {
                carry =0;
                A[i] = result;
            }
        }
        else
        {
            if(carry > 0)
            {
                int val = A[i];
                int result = val+carry;
                if(result > 9)
                {
                    carry = result / 10;
                    int remain = result % 10;
                    A[i] = remain;
                    
                }
                else 
                {
                    carry =0;
                    A[i] = result;
                }
            }
            
        }
    }
    //check for leading zeros
    bool bleadingzero = false;
    int startindex = 0;
    for(int i=0;i<size;i++)
    {
        if(A[i] == 0 && i == 0  && carry == 0)
        {
            bleadingzero = true;
            startindex = i+1;
        }
        
        if(i > 0)
        {
            if(bleadingzero == true && A[i] == 0)
            {
                bleadingzero = true;
                startindex = i+1;
            }
            
            if(A[i] > 0)
                bleadingzero = false;
        }
    }
    vector<int> number;
    if(carry > 0)
        number.push_back(carry);
        
    for(int i=startindex;i<size;i++)
        number.push_back(A[i]);
    
    return number;
}
