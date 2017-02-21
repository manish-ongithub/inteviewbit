/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
int mystrcmp(string str1, string str2)
{
    string a = str1;
    a+=(str2);
    string b = str2;
    b+= str1;
    
    int swap = 0;
    
    long long ia = atol(a.c_str());
    long long ib = atol(b.c_str());
    if(ia < ib)
        swap = 1;
        
    return swap;
    

  
}


// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right of pivot */
int partition (vector<int> &data, int l, int h)
{
    std::stringstream sleft;
    sleft << data[h];    // pivot
    int i = (l - 1);  // Index of smaller element
 
    for (int j = l; j <= h- 1; j++)
    {
        // If current element is smaller than or equal to pivot 
        std::stringstream sright;
        sright<<data[j];
        string strLeft = sleft.str();
        string strRight = sright.str();
        
        if (mystrcmp(strRight,strLeft) == 1)
        {
            i++;    // increment index of smaller element
            swap(&data[i], &data[j]);  // Swap current element with index
        }
    }
    swap(&data[i + 1], &data[h]);  
    return (i + 1);
}
 
/* arr[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSort(vector<int> &data, int l, int h)
{
    if (l < h)
    {
        int p = partition(data, l, h); /* Partitioning index */
        quickSort(data, l, p - 1);
        quickSort(data, p + 1, h);
    }
}

string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string result;
    int count = A.size();
    vector<int> data = A;
    
    quickSort(data,0,count-1);
    int zero = 0;
    for(int i=count - 1;i>=0;i--)
    {
        if(data[i]== 0)
            zero++;
        std::stringstream ss;
        ss<<data[i];
        result.append(ss.str());
    }
    if(zero == count)
        result = "0";
        
    return result;
}
