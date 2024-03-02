/**
 * @file main.cpp
 * @author Kimble Culley and Sydney Marshall
 * @date 2024-03-01
 * @brief Performs Image Stacking 
 * 
 * Initializes a stacker onject and performs the image stacking using the stacker class. 
 The tests include capturing user input for the image name and the number of images to stack.
 * The main function interacts with the Stacker class, calling methods to read individual PPM 
files,stack multiple images, and write the resulting stacked image to a new PPM file.

 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "stacker.h"

using namespace std;

int main() {
  // stacker class
  Stacker photo;

  //declares variables for user input
  string inFileName;
  stringstream temp;
  string temp2;
  int numImages;

  //prompts user to enter the image to stack
  cout << "Please enter the image you wish to stack: ";

  // gets user input for the name of the image
  cin >> inFileName;

  //creates a string stream to initalize the reading.
  temp << "ppms/ppms/" << inFileName << "/" << inFileName << "_" << "001" << ".ppm";
  //makes the string stream into a normal string.
  temp2 = temp.str();

  cout << "Please enter the number of images: ";
  // gets user input for number of images
  cin >> numImages;

  cout << "Stacking images: " << endl;

  //Initalizes the first read.
  photo.readFile(temp2);

  //reads in the data from however many images the user desires.
  photo.stackImage(inFileName, numImages);

  //Makes the output file name and sends it to the method
  //to put the information into the file

  string outFileName = inFileName + ".ppm";

  //writes final image to a new file 
  photo.outFile(outFileName);

  
   return 0;
}

