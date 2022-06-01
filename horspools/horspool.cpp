// Copyright 2022 Ana Boccanfuso
// CSCE 350 Assignment 3
// Implements Horspool's algorithm for string matching

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cstring>
using namespace std;
using namespace std::chrono;

// Creates shift table for uppercase
void shiftTableUpper(string pattern, char table[]) {
  int m = pattern.size();

  // initialize all elements of table with m
  for (int i = 0; i < 27; i++) {
    table[i] = m;
  }
  // set indices of shift table based on pattern
  for (int j = 0; j <= m - 2; j++) {
    // space is the last index of table (26)
    if (pattern[j] == ' ') {
      table[26] = m - 1 - j;
    }
    // shift based on ascii value
    table[(int)pattern[j]-65] = m - 1 - j;
  }
}

// Creates shift table for lowercase
void shiftTableLower(string pattern, char table[]) {
  int m = pattern.size();

  // initialize all elements of table with m
  for (int i = 0; i < 27; i++) {
    table[i] = m;
  }
  // set indices of shift table based on pattern
  for (int j = 0; j <= m - 2; j++) {
    // space is the last index of table (26)
    if (pattern[j] == ' ') {
      table[26] = m - 1 - j;
    }
    // shift based on ascii value
    table[(int)pattern[j]-97] = m - 1 - j;
  }
}

// performs horspool algorithm for uppercase
int horspoolUpper (string pattern, string text) {
  int m = pattern.size();
  int n = text.size();
  char table[27];
  // create shift table
  shiftTableUpper(pattern, table);
  int i = m - 1;  // position of the pattern's right end
  // find pattern
  while (i <= n - 1) {
    int k = 0;
    while (k <= m - 1 && pattern[m-1-k] == text[i-k]) {
      k++;
    }
    // pattern found, returns left-most index
    if (k == m) {
      return i - m + 1;
    }
    else {
      if (text[i] == ' ') {
        i = i + table[26];
      }
      i = i + table[(int)text[i] - 65];
    }
  }
  // returns -1 if pattern not found
  return -1;
}

// performs horspool algorithm for lowercase
int horspoolLower (string pattern, string text) {
  int m = pattern.size();
  int n = text.size();
  char table[27];
  // create shift table
  shiftTableLower(pattern, table);
  int i = m - 1;  // position of the pattern's right end
  // find pattern
  while (i <= n - 1) {
    int k = 0;
    while (k <= m - 1 && pattern[m-1-k] == text[i-k]) {
      k++;
    }
    // pattern found, returns left-most index
    if (k == m) {
      return i - m + 1;
    }
    else {
      if (text[i] == ' ') {
        i = i + table[26];
      }
      i = i + table[(int)text[i] - 97];
    }
  }
  // returns -1 if pattern not found
  return -1;
}

int main() {
  ifstream in("input.txt"); // input file that includes number of pattern and text
  string pattern;
  string text;
  if(in.is_open()) {  // opens file if it exists
    string line;  // stores line from input file

    getline(in, line);  // retrieves first line containing pattern
    pattern = line;

    getline(in, line);  // retrieves second line containing text
    text = line;
  }
  else {
    cout << "Can't open file" << endl; // error message if file cannot open
  }
  in.close(); // close input file

  int result;
  if (65 <= (int)pattern[0] && (int)pattern[0] <= 90) {
    auto start = high_resolution_clock::now();  // clock starts
    result = horspoolUpper(pattern, text);
    auto stop = high_resolution_clock::now(); // clock stops
    auto duration = duration_cast<microseconds>(stop - start); // calculates time of algorithm
    cout << "String matching execution time: " << duration.count() << " microseconds" << endl; // prints execution time
  }
  else {
    auto start = high_resolution_clock::now();  // clock starts
    result = horspoolLower(pattern, text); // algorithm runs
    auto stop = high_resolution_clock::now(); // clock stops
    auto duration = duration_cast<microseconds>(stop - start); // calculates time of algorithm
    cout << "String matching execution time: " << duration.count() << " microseconds" << endl; // prints execution time
  }

  ofstream out;
  out.open("output.txt"); // creates output file
  // prints -1 to output if pattern not found
  if (result == -1) {
    out << result << " (no match)" << endl;
  }
  // prints leftmost index of found pattern
  else {
    out << "Index of left end of first matching substring: " << result << endl;
  }
  out << endl;
  out.close();  // close output file

  return 0; // end program
}
