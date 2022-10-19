#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");

    std::ofstream file;
    const char * filenameStr = filename.c_str();
    file.open(filenameStr, std::ofstream::out | std::ofstream::trunc);
    if(file.fail()){
      return false;
    }

    file << "P3" << std::endl << width << " " << height << std::endl << 255 << std::endl;

    for(int i = 0; i < data.size(); i++){
      file << (unsigned int) data[i];
      if(num_channels == 1){
        file << " " << (unsigned int) data[i] << " " << (unsigned int) data[i] << " " << std::endl;
      }
      if(num_channels == 3){
        if((i+1)%3 == 0){
          file << std::endl;
        } else {
          file << " ";
        }
      }
    }
      file.close();
      return true; 
}
