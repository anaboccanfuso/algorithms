// Copyright 2022 Ana Boccanfuso
// CSCE 350 Assignment 4
// Implements Floyd's algorithm for all pairs shortest paths

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main() {
  ifstream in("input.txt"); // input file that includes distance matrix
  vector<vector<float>> arr;  // to store matrix values
  if(in.is_open()) {  // opens file if it exists
    string line;  // stores line from input file
    int n = 0;  // used to count number of rows/columns
    while (getline(in, line)) {
      arr.push_back(vector<float>());  // adds a vector to the 2d vector
      size_t pos = 0;
      while ((pos = line.find(" ")) != string::npos) {  // get individual numbers
        float temp = stof(line.substr(0, pos));   // get number and convert to float
        arr[n].push_back(temp); // add number to 2d matrix
        line.erase(0, pos + 1); // delete number and space that has already been added
      }
      float last = stof(line);  // convert last number to float
      arr[n].push_back(last);   // add last number of line to vector
      n++;  // increase row count
    }
    in.close(); // close input file

    // implements floyd's algorithm with the 2d vector (using pseudocode)
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          // changes distance accordingly
          arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
        }
      }
    }

    ofstream out; // open output stream
    out.open("output.txt"); // creates output file
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        out << arr[i][j] << " ";  // write float in same line to output file
      }
      out << "\n";  // skip line to write next line
    }
    out.close();  // close output file

  }


  else {
    cout << "Can't open file" << endl; // error message if file cannot open
    exit(0);
  }
  return 0; // end program
}
