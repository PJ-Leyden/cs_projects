#include <iostream>
#include <algorithm>
#include <cstdlib>

void generate(int arr[], int len) {
  for (int i = 0; i < len; ++i) {
    arr[i] = rand() % 100;
  }
} 

void printArr(const int arr[], int len) {
  for (int i = 0; i < len; ++i) {
    std::cout << arr[i];
    if (!((i + 1) == len))
      std::cout << ", ";
  }
  std::cout << "\n";
}

void select (int arr[], int len)
{
  int i,j;

  for (j = 0; j < len-1; j++) {
    int iMin = j;

    for ( i = j+1; i < len; i++) {
      if (arr[i] < arr[iMin]) {
	iMin = i;
      }
    }

    if(iMin != j) {
      int temp = arr[j];
      arr[j] = arr[iMin];
      arr[iMin] = temp;
    }
  }
}

int main(int argc, char* argv[]) {

  if (argc != 2) {
    std::cout << "usage: ./sorted NumElements\n";
    return -1;
  }
  
  int len = atoi(argv[1]);
  int* array = new int[len];

  generate(array, len);
  select(array, len);
  printArr(array, len);

  generate(array, len);
  std::sort(array, array + len);
  printArr(array, len);

  delete[] array;
  return 0;
}
