/**
 * @file main.cpp
 * @author Kimble Culley & Sydney
 * @date 2024-03-01
 * @brief asks the user for an input, creates an object stacks image, returns image as name.ppm
 * 
 * Asks the user for an input, creates an object called photo, 
 * and then uses the methods from the stacker class to stack however many images the user desires.
 */


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
  //creates a string stream to initalize the reading.
  temp << "ppms/ppms/" << inFileName << "/" << inFileName << "_" << "001" << ".ppm";
  //makes the string stream into a normal string.
  temp2 = temp.str();
  cout << "Please enter the number of images: ";

  cin >> numImages;

  cout << "Stacking images: " << endl;

  //Initalizes the first read.
  photo.readFile(temp2);

  //reads in the data from however many images the user desires.
  photo.stackImage(inFileName, numImages);

  //Makes the output file name and sends it to the method
  //to put the information into the file
  string outFileName = inFileName + ".ppm";
  photo.outFile(outFileName);

  
   return 0;
}

