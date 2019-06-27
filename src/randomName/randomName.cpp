#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void name(string& current);

int main(int argc, char const* argv[])
{
  ofstream outFile;
  outFile.open("..\\data\\dataGraph.txt");
  if (!outFile.is_open()) {
    return EXIT_FAILURE;
  }

  int lines;
  if (argc == 2) {
    lines = stoi(argv[1]);
  } else {
    lines = 1000000;
  }

  string current = "A";
  for (int i = 0; i < lines; ++i) {
    outFile << current << '\n';
    name(current);
  }

  return EXIT_SUCCESS;
}

void name(string& current)
{
  char* tail = &current.back();
  if (*tail == 'Z') {
    string z = "Z";
    auto iter = find_end(current.rbegin(), current.rend(), z.begin(), z.end());
    if (iter == current.rend() - 1) {
      fill(current.begin(), current.end(), 'A');
      current.push_back('A');
      return;
    } else {
      ++(*(iter + 1));
      for (; iter != current.rbegin() - 1; --iter) { *iter = 'A'; }
    }
  } else {
    ++(*tail);
  }
}