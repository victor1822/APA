#ifndef RADIXSORT_HPP_INCLUDED
#define RADIXSORT_HPP_INCLUDED
#include <vector>
#include <iostream>
#include "CountSort.hpp"
using namespace std;
 
// A utility function to get maximum value in arr[]
int getMax(vector<int> ent)
{
    int mx = ent[0];
    for (int i = 1; i < ent.size()-1; i++)
        if (ent[i] > mx)
            mx = ent[i];
    return mx;
}

void rs(vector<int> &ent)
{
    // Find the maximum number to know number of digits
    int m = getMax(ent);
 
    for (int exp = 1; m/exp > 0; exp *= 10)
        cs(ent, exp);//chama o counting sort
}


#endif // RADIXSORT_HPP_INCLUDED
