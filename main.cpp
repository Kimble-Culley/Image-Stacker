
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "stacker.h"

using namespace std;

int main() {

  Stacker photo;

  string inFileName;
  stringstream temp;
  string temp2;
  int numImages;

  
  cout << "Please enter the image you wish to stack: ";

  cin >> inFileName;

  temp << "ppms/ppms/" << inFileName << "/" << inFileName << "_" << "001" << ".ppm";
  temp2 = temp.str();
  cout << "Please enter the number of images: ";

  cin >> numImages;

  cout << "Stacking images: " << endl;


  photo.readFile(temp2);

  photo.stackImage(inFileName, numImages);

  string outFileName = inFileName + ".ppm";
  photo.outFile(outFileName);

  
   return 0;
}

