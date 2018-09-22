/**
 * @brief  Application to run sorting algorithms on random int data
 *
 * @author Dale Haverstock
 * @date   2012-04-19
 */

// sort library
//

//==============================================================================
#include "sort_lib.h"
#include <vector>

//==============================================================================
// Make shorter type names
typedef std::vector<int>::size_type Vec_Idx;

//==============================================================================
// Function declarations, uppercase so those stand out
void quick_sort(std::vector<int>& data, int left, int right);
void SWAP(int& n1, int& n2);
bool LESS_THAN(int n1, int n2);
bool GREATER_THAN(int n1, int n2);

//==============================================================================
void quick_sort(std::vector<int>& data)
{
    // Do nothing if empty vector
    if (data.size() == 0)
        { return; }

    // Do the sort
    quick_sort(data, 0, data.size() - 1);
}

//==============================================================================
// The unsigned ints cause problems here, jdx may go to -1.
// Subscripts are cast so there are no warnings.
void quick_sort(std::vector<int>& data, int left, int right)
{
      // Calculate the pivot
      int pivot = data[Vec_Idx((left + right) / 2)];

      // Partition
      int idx = left, jdx = right;
      while (idx <= jdx) {
            while (LESS_THAN(data[Vec_Idx(idx)], pivot))
                  idx++;

            while (GREATER_THAN(data[Vec_Idx(jdx)], pivot))
                  jdx--;

            if (idx <= jdx)
            {
                  SWAP(data[Vec_Idx(idx)], data[Vec_Idx(jdx)]);
                  idx++;
                  jdx--;
            }
      }

      // Recurse
      if (left < jdx)
            { quick_sort(data, left, jdx); }

      if (idx < right)
            { quick_sort(data, idx, right); }
}

//==============================================================================
void selection_sort(std::vector<int>& data)
{
    // Do nothing if empty vector (note unsigned 0 - 1 is a big number)
    if (data.size() == 0)
        { return; }

    // Index of last element in vector, also last in unsorted part
    Vec_Idx last = data.size() - 1;

    // Do the sort
    while (last > 0)
    {
        // Find greatest in unsorted part
        Vec_Idx idx_of_greatest = 0;
        for (Vec_Idx idx = 0; idx <= last; ++idx)
        {
            if ( LESS_THAN(data[idx_of_greatest], data[idx]) )
            {
                // Remember as new greatest so far
                idx_of_greatest = idx;
            }
        }

        // Swap last in unsorted with greatest in unsorted part
        SWAP(data[last], data[idx_of_greatest]);

        // Increase sorted part
        --last;
    }
}

//==============================================================================
void bubble_sort(std::vector<int>& data)
{
    // Go through vector repeatedly
    for(Vec_Idx limit = data.size(); limit > 0; limit--)
    {
        // Go through vector once, swap element and next element if out of order
        for(Vec_Idx idx = 0; idx < limit - 1; idx++)
        {
            if( LESS_THAN(data[idx + 1], data[idx]) )
            {
                SWAP(data[idx],data[idx + 1]);
            }
        }
    }
}

//==============================================================================
// This is here so the number of calls can be counted.
void SWAP(int& n1, int& n2)
{
    std::swap(n1, n2);
}

//==============================================================================
// This is here so the number of calls can be counted.
bool LESS_THAN(int n1, int n2)
{
    return n1 < n2;
}

//==============================================================================
// This is here so the number of calls can be counted.
bool GREATER_THAN(int n1, int n2)
{
    return n1 > n2;
}

