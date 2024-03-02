/**
 * @file stacker.h
 * @author Kimble Culley and sydney
 * @date 2024-02-21
 * @brief a class for storing the information from the desired photos
 * 
 * A class to read in the information from the pmm files into the necessary ints and strings,
 * as well as the methods to read the files, average the data, and output the data to a ppm file. 
 */



#ifndef STACKER_H
#define STACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class Stacker{
private:
  std::string magic_number;
  int width;
  int height;
  int max_color;
  struct pixel{
    int red;
    int green;
    int blue;
  };
  std::vector<pixel> pixels;
  

public:
  Stacker();
  ~Stacker();
  //Reads the first file to initialize the data.
  void readFile(std::string& FileName);

  //Uses a for loop to make each file name, and read in the data into a
  //new vector to then add and average the data per pixel.
  void stackImage(std::string& baseFileName, int numImages);

  //Puts the magic number, width, height, max_color, and all the individual
  //pixel data into one output file with the same name that was used for input.
  void outFile(std::string& outFileName);

};
#endif //STACKER_H
