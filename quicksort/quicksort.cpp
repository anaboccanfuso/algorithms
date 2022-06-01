// Copyright 2022 Ana Boccanfuso

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <array>
using namespace std;
using namespace std::chrono;

// partitions and compares the array
int partition(float arr[], int start, int end) {
  float pivot = arr[start]; // the value of the pivot
  int pivotIndex = start;  // this acts as "i"

  // compares values other than the pivot and changes the
  // index accordingly by swapping 
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot) {
      pivotIndex++;
      swap(arr[i], arr[pivotIndex]);
    }
  }
  swap(arr[pivotIndex], arr[start]);
  return pivotIndex;
}

void quickSort (float arr[], int start, int end) {
  // base case
  if (start >= end)
    return;

  // partition the array
  int part = partition(arr, start, end);

  // sorting left side
  quickSort(arr, start, part - 1);

  // sorting right side
  quickSort(arr, part + 1, end);

}

// Main function that takes in an input file and stores the values
// in a vector of type floating point. Then, it transfers the vector
// to an array, starts the clock, calls the quicksort function, ends
// the clock, outputs the execution time, and writes the sorted values
// to output.txt.
int main() {
  vector<float> vect;
  ifstream in("input.txt");
  // opens the input file
  if (in.is_open()) {
    string line;
    while (getline(in, line, ' ')) {
      float num = stof(line);
      // adding each value to the vector
      vect.push_back(num);
    }
  }
  in.close();
  int n = vect.size();

  // array that vector values will be transferred to
  float arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = vect[i];
  }
  // clock begins
  auto start = high_resolution_clock::now();
  // calls quicksort on the array with the full elements
  quickSort(arr, 0, n - 1);
  // clock stops
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // outputs the execution time  to the terminal
  cout << "Quicksort execution time: " << duration.count() << " microseconds" << endl;

  // writes sorted values to output.txt
  ofstream out;
  out.open("output.txt");
  for (int i = 0; i < n; i++) {
    out << arr[i] << " ";
  }
  out << endl;
  out.close();

  // ends program
  return 0;
}
