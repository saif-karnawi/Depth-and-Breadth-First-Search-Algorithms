/*
*  File: censorColorPicker.cpp
*  Implements the censor color picker for CPSC 221 PA2.
*
*/

#include "censorColorPicker.h"

#include <math.h> // gives access to sqrt function

/*
*  Useful function for computing the Euclidean distance between two PixelPoints
*/
double PointDistance(PixelPoint a, PixelPoint b) {
  unsigned int diff_x, diff_y;
  if (a.x > b.x)
    diff_x = a.x - b.x;
  else
    diff_x = b.x - a.x;
  if (a.y > b.y)
    diff_y = a.y - b.y;
  else
    diff_y = b.y - a.y;
  return sqrt(diff_x * diff_x + diff_y * diff_y);
}

CensorColorPicker::CensorColorPicker(unsigned int b_width, PixelPoint ctr, unsigned int rad, PNG& inputimage)
{
  blockwidth = b_width;     // width of a mosaic block in pixels.
  center = ctr;             // middle/center point of mosaic area
  radius = rad;             // maximum pixel distance away from center where the mosaic color will be applied
  img = inputimage;         // Original image used in flood fill algorithm
  blockyimg.resize(img.width(), img.height());
  
  unsigned y = 0;
  int loopY = 0;
  unsigned blockwidY = blockwidth; 
  // going thru in the y direction
  for (unsigned b = 0; b < (img.height() / blockwidth); b++) {
    // initizing counters
    int loopX = 0;
    unsigned x = 0;
    unsigned blockwidX = blockwidth;

    // going thru in the x direction
    for (unsigned a = 0; a < (img.width() / blockwidth); a++) {
      double totalH = 0;
      double totalS = 0;
      double totalL = 0;
      double totalA = 0;
      int pixels = 0;
      
      

      // get the total HLSA values (going in x and then in y)
      for (unsigned d = y; d < blockwidY; d++) {
        for (unsigned c = x; c < blockwidX; c++) {
          HSLAPixel *pixel = img.getPixel(c, d);

          totalH += pixel->h;
          totalS += pixel->s;
          totalL += pixel->l;
          totalA += pixel->a;
          pixels++;

        }
      }

      double avgH = totalH / pixels;
      double avgS = totalS / pixels;
      double avgL = totalL / pixels;
      double avgA = totalA / pixels;
      
      // fill the block with the average value (going in x and then in y)
      for (unsigned f = y; f < blockwidY; f++) {
        for (unsigned e = x; e < blockwidX; e++) {
          HSLAPixel *pixel = blockyimg.getPixel(e, f);

          //calculate the average value
          pixel->h = avgH;
          pixel->s = avgS;
          pixel->l = avgL;
          pixel->a = avgA;
        }
      }

      loopX++;
      x = loopX*blockwidth;
      // update the bound
      if ((blockwidX + blockwidth) < img.width()) {
        blockwidX += blockwidth;
      } else {
        blockwidX = img.width();
      }
    }

    loopY++;
    y = loopY*blockwidth;
    if ((blockwidY + blockwidth) < img.height()) {
        blockwidY += blockwidth;
      } else {
        blockwidY = img.height();
      }
  }  
}



HSLAPixel CensorColorPicker::operator()(PixelPoint p)
{
  HSLAPixel *pixel = img.getPixel(p.x, p.y);

  if (PointDistance(center, p) > radius) {

    return *pixel;

  }

  HSLAPixel *ans = blockyimg.getPixel(p.x, p.y);

  return *ans;
}