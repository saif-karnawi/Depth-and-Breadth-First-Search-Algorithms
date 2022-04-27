/*
*  File: imageTileColorPicker.cpp
*  Implements the image tile color picker for CPSC 221 PA2.
*
*/

#include "imageTileColorPicker.h"

ImageTileColorPicker::ImageTileColorPicker(PNG& otherimage) {
  // complete your implementation below
  img_other = otherimage;
  
}

HSLAPixel ImageTileColorPicker::operator()(PixelPoint p) {
  // complete your implementation below

  int x = p.x;
  int y = p.y;

  while(x >= img_other.width()) {
      x -= img_other.width();
  }

  while(y >= img_other.height()) {
      y -= img_other.height();
  }

  return *img_other.getPixel(x, y);

}