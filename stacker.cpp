/**
 * @file stacker.cpp
 * @author Kimble Culley and Sydney
 * @date 2024-02-21
 * @brief idk yet
 * 
 * idk yet
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "stacker.h"

using namespace std;


Stacker::Stacker(){
  int width = 0;
  int height = 0;
  int max_color = 0;
}

Stacker::~Stacker(){
  int width = 0;
  int height = 0;
  int max_color = 0;
  
}








void Stacker::readFile(string FileName){

  ifstream File(FileName);
  
  if(File.is_open()){
    cout << "file opened successfully" << endl;
    File >> magic_number >> height >> width >> max_color;
    cout << magic_number << " " << height << " " << width << " " << max_color <<  endl;


    while(!File.eof()){
      pixel pixel;
      File >> pixel.red >> pixel.green >> pixel.blue;
      pixels.push_back(pixel);
    }

    pixels.clear();


    for(int i = 0; i < (height * width); i++){
      cout << pixels[i].red << " " <<  pixels[i].green << " " << pixels[i].blue << endl;

    }
    File.close();
  }
  else{
    cout << "file not opened"  << endl;
  }
}


void Stacker::outFile(string FileName){

  ofstream FileOut(FileName + ".ppm");
  
  if(FileOut.is_open()){
    FileOut << magic_number << endl;
    FileOut << width << " " << height << endl;
    FileOut << max_color << endl;

    for(int i = 0; i < (height * width); i++){
      FileOut << pixels[i].red << " " << pixels[i].green << " " << pixels[i].blue << endl;
    }

    FileOut.close();
  }
}

//void Stacker::Average(){
  //int sumRed = 0;
  //int sumGreen = 0;
  //int sumBlue = 0;

  //for(int i = 0; i < (height * width); i++){
    //sumRed = pixels[
		    //}
