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


/**
 * @class Stacker
 * @brief Image stacker class for taking stacking images 
 */
class Stacker{
private:
  std::string magic_number; //magic number for PPM image format
  int width;
  int height;
  int max_color;

  /**
   * @struck pixel 
   * @brief color info of a pixel 
   */
  struct pixel{
    int red;
    int green;
    int blue;
  };

  std::vector<pixel> pixels; //vector to store pixel data 
  

public:


/**
 * constructor for Stacker class
 *
 * Initializes image info values 
 */
  Stacker();

  //destructor for stacker class
  ~Stacker();


/**
 * reads the first image file to initialize data  
 * @param std::string& FileName 
 * @return void 
 */
  void readFile(std::string& FileName);

  

/**
 * reads in multiple image files, stacks their pixel data, and gets the avg the data per pixel
 * @param std::string& baseFileName 
 * @param int numImages  
 * @return void 
 */
  void stackImage(std::string& baseFileName, int numImages);

 

/**
 * puts the magic number, width, height, max_color, and all the individual pixel data into one
 output file with the same name that was used for input
 * @param std::string& outFileName 
 * @return void 
 */
  void outFile(std::string& outFileName);

};
#endif //STACKER_H
