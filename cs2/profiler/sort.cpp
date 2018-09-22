/**
 * @brief  Application to run sorting algorithms on random int data
 *
 * @author Dale Haverstock
 * @date   2012-04-19
 */

//==============================================================================
#include "sort_lib.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

//==============================================================================
// Using declarations
using std::string;
using std::vector;
using std::cout;
using std::cerr;

//==============================================================================
// Function declarations
void process_command_line(Options& opts, int argc, char* argv[]);
void generate_random_data(vector<int>& data, int size, int seed, int mod);
void output_data(const vector<int>&);
void output_usage_and_exit(const string& cmd);
void output_error_and_exit(const string& msg);

//==============================================================================
int main(int argc, char* argv[])
{
    // Options container
    Options opts;

    // Get values from the command line, opts may be changed
    process_command_line(opts, argc, argv);

    // Generate data
    vector<int> data;
    generate_random_data(data, opts._data_size, opts._seed, opts._mod);

    // Output data before sorting
    if(opts._output_data)
        { cout << "\nData Before: "; output_data(data); } 

    // Sort, if a sort was specified, there is no default
    if (opts._quick_sort)     { quick_sort(data);      }
    if (opts._selection_sort) { selection_sort(data);  }
    if (opts._bubble_sort)    { bubble_sort(data);     }
    if ( !opts._quick_sort      &&
         !opts._selection_sort  &&
         !opts._bubble_sort  )
        { output_error_and_exit("No sort specified."); }

    // Output data after sorting
    if(opts._output_sorted_data)
        { cout << "\nData After: "; output_data(data); } 

    return 0;
}

//==============================================================================
void generate_random_data(vector<int>& vec, int size, int seed, int mod)
{
    // Resize vector
    vec.resize(size);

    // Set random number generator seed
    srandom(static_cast<unsigned int>(seed));

    // Put random values in vector
    for (vector<int>::size_type idx = 0; idx < vec.size(); ++idx)
    {
        if(mod) { vec[idx] = random() % mod; }
        else    { vec[idx] = random();       }
    }
}

//==============================================================================
void output_data(const vector<int>& vec)
{
    // Number of columns, column width
    const int cols  =  7;
    const int width = 10;

    // Output vector elements
    for (vector<int>::size_type idx = 0; idx < vec.size(); ++idx)
    {
        // Output newline to end row
        if ( ! (idx % cols) )
           { cout  << "\n"; }

        cout << std::setw(width) << vec[idx] << " ";
    }

    cout << '\n';
}

//==============================================================================
// Note:
//   * No check for C-string to int conversion success
//
void process_command_line(Options& opts, int argc, char* argv[])
{
    // Useage message if no command line args
    if (argc == 1)
        { output_usage_and_exit(argv[0]); }

    // Go through the argumets
    for (int idx = 1; idx < argc; ++idx)
    {
        // Standard library string from C-string
        string opt(argv[idx]);

        // Process the option
        if (opt == "-h")   { output_usage_and_exit(argv[0]); }
        if (opt == "-qs")  { opts._quick_sort         = true;  }
        if (opt == "-ss")  { opts._selection_sort     = true;  }
        if (opt == "-bs")  { opts._bubble_sort        = true;  }
        if (opt == "-od")  { opts._output_data        = true;  }
        if (opt == "-osd") { opts._output_sorted_data = true;  }
        if (opt == "-sz")
        {
            if (idx + 1 < argc) { ++idx; opts._data_size = atoi(argv[idx]); }
            else                { output_error_and_exit("Value for -sz option is missing."); }
        }
        if (opt == "-rs")
        {
            if (idx + 1 < argc) { ++idx; opts._seed = atoi(argv[idx]); }
            else                { output_error_and_exit("Value for -rs option is missing."); }
        }
        if (opt == "-mod")
        {
            if (idx + 1 < argc) { ++idx; opts._mod = atoi(argv[idx]); }
            else                { output_error_and_exit("Value for -mod option is missing."); }
        }
        if ( (opt != "-h")   &&
             (opt != "-qs")  &&
             (opt != "-ss")  &&
             (opt != "-bs")  &&
             (opt != "-od")  &&
             (opt != "-osd") &&
             (opt != "-sz")  &&
             (opt != "-rs")  &&
             (opt != "-mod") )
        {
           output_error_and_exit(string("Error: Bad option: ") + opt);
        }
    }
}

//==============================================================================
void output_usage_and_exit(const string& cmd)
{
    cout << 
       "Usage: " << cmd << " [options]\n"
       "  Options:\n"
       "     -sz  int  The number of data items\n"
       "     -rs  int  The random number generator seed\n"
       "     -mod int  The mod value for random numbers\n"
       "     -od       Output data to be sorted\n"
       "     -osd      Output sorted data\n"
       "     -qs       Use quick sort\n"
       "     -ss       Use selection sort\n"
       "     -bs       Use bubble sort\n"
       "     -h        This message\n"
       "\n"
       "  A sort must be specified, there is no default sort.\n"
       "  If more than 1 sort is specified then the first sort\n"
       "  specified from the following order will be done.\n"
       "     1. quick\n"
       "     2. selection\n"
       "     3. bubble\n";

    exit(0);
}

//==============================================================================
void output_error_and_exit(const string& msg)
{
    cerr << "Error: " << msg << "\n";

    exit(1);
}

