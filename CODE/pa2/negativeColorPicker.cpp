/*
*  File: negativeColorPicker.cpp
*  Implements the negative color picker for CPSC 221 PA2.
*
*/

#include "negativeColorPicker.h"

NegativeColorPicker::NegativeColorPicker(PNG& inputimg)
{
  // complete your implementation below
  img = inputimg;
}

HSLAPixel NegativeColorPicker::operator()(PixelPoint p)
{
  // complete your implementation below
  
  HSLAPixel *h = img.getPixel(p.x, p.y);

  int hue = h->h;

  h->h = (hue + 180) % 360;
  h->l = abs(h->l - 1);

  return *h;
} 
