
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "stacker.h"

using namespace std;

int main() {

  Stacker photo;
  
  cout << "Please enter the image you wish to stack: ";

  cin >> photo.FileName;

  photo.readFile(photo.FileName);
  photo.outFile(photo.FileName);

  
  
  return 0;
}
