/**
 * @file stacker.h
 * @author Kimble Culley and sydney
 * @date 2024-02-21
 * @brief idk yet
 * 
 * idk ey
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
  std::string FileName;
  int NumOfImages;
  Stacker();
  ~Stacker();

};
#endif //STACKER_H
