
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

  cout << "Please enter the number of images: ";

  cin >> photo.NumOfImages;

  cout << "Stacking images: " << endl;

    
  for(int i = 1; i <= photo.NumOfImages; i++){
    stringstream FullName;
    FullName << "ppms/ppms/" << photo.FileName << "/" << photo.FileName << "_";

    if(i < 10)
      FullName << "00" << i;
    else if(i >= 10)
      FullName << "0" <<i;

    FullName << ".ppm";


    photo.Array.push_back(FullName.str());
    cout << photo.Array[i-1] << endl;
    //photo.readFile(NewName);

  
  }
  //photo.outFile(photo.FileName);
  int x = 0;
  cin >> x;
  cout << photo.Array[x];
    return 0;
}
