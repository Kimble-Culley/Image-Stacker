/**
 * @file stacker.cpp
 * @author Kimble Culley and Sydney
 * @date 2024-02-21
 * @brief The methods for reading, averaging, and outputting the data.
 * 
 * Reads in the data over the amount of files the user inputs in main,
 * creates the full address for each file and then reads in the data
 * adding them all up then averaging them before putting the averaged
 * data back into a file using the users original input as the name.
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


void Stacker::readFile(string &FileName){
  
ifstream file(FileName);

if(!file.is_open()){
  cout << "error1" <<endl;
}

file >> magic_number >> width >> height >> max_color;

  pixels.resize(width * height);

  for(int i = 0; i < width * height; i++){
    file >> pixels[i].red >> pixels[i].green >> pixels[i].blue;
  }

  pixels.clear();
  file.close();
}

void Stacker::stackImage(string &baseFileName, int numImages){

   pixels.resize(width * height);

  for(int i = 1; i <= numImages; i++){
      
    stringstream FileName;
    //Creates the full file address to be read in.
    FileName << "ppms/ppms/" << baseFileName << "/" << baseFileName << "_";

    if(i < 10)
      FileName << "00" << i;
    else if(i >= 10)
      FileName << "0" << i;

    FileName << ".ppm";

    string name = FileName.str();

    cout << name << endl;

    ifstream file(name);

    if(!file.is_open()){
      cout << "error2";
    }
    
    vector<pixel> currentPixels(width * height);


      file >> magic_number >> width >> height >> max_color;

    
    for(int j = 0; j < width * height; j++){
      file >> currentPixels[j].red >> currentPixels[j].green >> currentPixels[j].blue;

      //Adds all the pixel data to the previous ones base on the number of images.
      pixels[j].red += currentPixels[j].red;
      pixels[j].green += currentPixels[j].green;
      pixels[j].blue += currentPixels[j].blue;
    }

    file.close();
  }
  for(int i = 0; i < width * height; i++){
    //Averages the total pixel value by the amount of pictures inputted
      pixels[i].red /= numImages;
      pixels[i].green /= numImages;
      pixels[i].blue /= numImages;
    }
  
}

void Stacker::outFile(string& outputFilename){
  ofstream outputFile(outputFilename);

  if(!outputFile.is_open()){
    cout << "error3";
  }

  outputFile << magic_number << endl;
  outputFile << width << " " << height << endl;
  outputFile << max_color << endl;

  for(int i = 0; i < width * height; i++){
    //Outputs the data into the new file.
    outputFile << pixels[i].red << " " << pixels[i].green << " " << pixels[i].blue << endl;
  }
  cout << "Stacking succeeded." << endl;
  cout << "Output written to: " << outputFilename << endl;
  outputFile.close();
}
