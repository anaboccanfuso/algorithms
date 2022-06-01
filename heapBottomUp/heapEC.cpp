// Copyright 2022 Ana Boccanfuso
// CSCE 350 Assignment 2
// Constructs a heap from the elements of a given array
// by the bottom-up algorithm

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

void heapify(int *arr, int i, int size) {
  int v = arr[i];
  int k = i;

  while(2*k <= size) {
    int j = 2*k;
    if (j < size && arr[j] < arr[j+1]) {
      j++;  // if there are two children, use larger child
    }
    if (v >= arr[j])
      break;
    else {
      arr[k] = arr[j];  // swap parent key with the larger child
      k = j;  // keep checking the key
    }
  }
  arr[k] = v;
  return;
}

void heapSort(int *arr, int size) {
    // extract each element from heap
    for (int i = size; i > 0; i--) {
      swap(arr[1], arr[i]); // move current root to end
      heapify(arr, 1, i-1); // make a heap on what's left
    }
}

void build (int *arr, int size) {
  for (int i = size/2; i >= 1; i--) { // works from bottom up
    heapify(arr, i, size); // call heap function
  }
}

int main() {
  vector<int> vect; // vector to which integers will be added to from input file
  ifstream in("input.txt"); // input file that includes number of elements and list of integers
  int keys; // initialize number of elements variable
  if(in.is_open()) {  // opens file if it exists
    string line;  // stores line from input file

    getline(in, line);  // retrieves first line containing number of integers
    keys = stoi(line);  // converts from string to integer and stores it in the variable

    while(getline(in, line, ' ')) { // gets each number in the second line to be sorted
      int num = stoi(line); // converts string to integer
      vect.push_back(num);  // adds integer to vector
    }
  }
  else {
    cout << "Can't open file" << endl; // error message if file cannot open
  }
  in.close(); // close input file

  int arr[keys+1];  // initialize integer array to be used as heap with appropriate size
  for (int i = 1; i <= keys+1; i++) { // converts vector to array with arr[0] empty
    arr[i] = vect[i-1];
  }

  build(arr, keys); // algorithm runs

  ofstream out;
  out.open("output.txt"); // creates output file
  out << "Heap: ";
  for (int i = 1; i < keys+1; i++) {  // prints sorted heap to output file
    out << arr[i] << " ";
  }
  out << endl;
  heapSort(arr, keys);
  out << "Sorted Heap: ";
  for (int i = keys; i > 0; i--) {
    out << arr[i] << " ";
  }
  out << endl;
  out.close();  // close output file

  return 0; // end program
}
