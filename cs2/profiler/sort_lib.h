/**
 * @brief  Application to run sorting algorithms on random int data
 *
 * @author Dale Haverstock
 * @date   2012-04-19
 */

#ifndef SORT_LIB_H
#define SORT_LIB_H

//==============================================================================
#include <vector>

//==============================================================================
struct Options
{
    // Option values
    int  _seed;
    int  _data_size;
    int  _mod;
    bool _output_data;
    bool _output_sorted_data;
    bool _bubble_sort;
    bool _selection_sort;
    bool _quick_sort;

    // Defaults
    Options()
      : _seed(0),
        _data_size(0),
        _mod(0),
        _output_data(false),
        _output_sorted_data(false),
        _bubble_sort(false),
        _selection_sort(false),
        _quick_sort(false)
    { }
};

//==============================================================================
void selection_sort(std::vector<int>&);
void quick_sort(std::vector<int>&);
void bubble_sort(std::vector<int>&);

#endif

