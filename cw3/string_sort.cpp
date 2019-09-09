#include <iostream>

using namespace std;

//first sort ARR by length (not neccessarily stable) [must be O(n) - bucket sort or counting sort]
//additional array W of length k (max_string_length)
//  i-th element holds index of the first element in the ARR of length  >i

// moving through W we radix sort the sublists of words of length >i starting from index W[i] in ARR


void string_sort(string tab[], int N)
{

}