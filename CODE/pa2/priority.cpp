
/*
* File:        priority.cpp
* Description: Implements a priority ordering structure specially made for determining the
*              order of neighbours visited in PA2's filler::fill function.
*              Note that this does NOT serve the same purpose as the stack/queue
*              ordering structure which you have also been asked to implement.
Expand
priority.cpp
5 KB
butterfly_effect — Today at 6:38 PM
ty i don't think its remove then
cuz what i did is used another OrderingStructure called track
and still same seg fault gets thrown
so the error is not in priority
Anson — Today at 6:39 PM
Try submitting to PL
My buddy said he got one fail test
But still got 100%
butterfly_effect — Today at 6:40 PM
i did but because its throwing segfault
we actually get no points for fill
﻿
/*
* File:        priority.cpp
* Description: Implements a priority ordering structure specially made for determining the
*              order of neighbours visited in PA2's filler::fill function.
*              Note that this does NOT serve the same purpose as the stack/queue
*              ordering structure which you have also been asked to implement.
*
*              Ignoring resize costs, any single insertion or removal operation
*              should cost at most O(n), where n is the number of PixelPoints
*              stored in the collection.
*
* Date:        2022-02-10 02:04
*
*/

#include "priority.h"
#include <assert.h>

using namespace cs221util;
using namespace std;

/*
*  Default constructor
*  Initializes refcolor to the default color according to the HSLAPixel implementation.
*/
PriorityNeighbours::PriorityNeighbours() {
  refcolor = HSLAPixel();
  //points = vector<PixelPoint>();
}

/*
*  Parameterized constructor
*  Initializes refcolor to the supplied value.
*/
PriorityNeighbours::PriorityNeighbours(HSLAPixel ref) {
  refcolor = ref; 
  //points = vector<PixelPoint>();  
}

/*
*  Inserts an item into the collection
*  PARAM: p - item to be inserted
*  POST:  the collection contains p, along with all previously existing items.
*/
void PriorityNeighbours::Insert(PixelPoint p) {
  points.push_back(p);
}

/*
*  Removes and returns an item from the collection satisfying the priority condition
*  PRE:    the collection is not empty (but it would be good to check anyway!).
*  POST:   the item satisfying the priority condition is removed from the collection.
*  RETURN: the item satisfying the priority condition
*
*  Priority condition:
*    The PixelPoint in the collection whose color is the minimum distance away
*    from the reference color is the priority item to be returned.
*
*    In case of multiple items with the same priority value (i.e. minimal distance
*    away from the reference color), the one with the minimal y-coordinate will be
*    selected.
*    In case of multiple items with the same priority value and the same y-coordinate,
*    the one with the minimal x-coordinate will be selected.
*
*    ***ATTENTION*** The dist() function in HSLAPixel.h will be very helpful!
*
*  Combined with Insert(), think about the time complexity of maintaining the
*  priority order and/or accessing the priority element in this specific application!
*/
PixelPoint PriorityNeighbours::Remove() {

  PixelPoint target = points[0];
  double dist = refcolor.dist(points[0].color);
  int index = 0;

  for (int i = 1; i < points.size(); i++) {

    // case 1: when the new pp is closer than prev min
    if (refcolor.dist(points[i].color) < dist) {
      dist = refcolor.dist(points[i].color);
      target = points[i];
      index = i;
    }

    // case 2: when the new pp has the same dist as the prev min
    if (refcolor.dist(points[i].color) == dist) {
      //find the min y distance
      if (points[i].y < target.y) {
        dist = refcolor.dist(points[i].color);
        target = points[i];
        index = i;
      }

      // if the y is the same then find min x
      if (points[i].y == target.y) {
        if (points[i].x < target.x) {
          dist = refcolor.dist(points[i].color);
          target = points[i];
          index = i;
        }
      }
    }
  }
  
  //swap it to the back of the array and then remove it from the end
  swap(points[index], points[points.size() - 1]);
  points.pop_back();

  //return the target
  return target;
}

/*
*  Checks if the collection is empty
*  RETURN: true, if the collection is empty
*          false, otherwise
*/
bool PriorityNeighbours::IsEmpty() const {
  // complete your implementation below
  return points.empty();
}

/*
*  Returns the value of the reference color
*/
HSLAPixel PriorityNeighbours::GetReferenceColor() const {
  // complete your implementation below
  
  return refcolor; // REPLACE THIS STUB
}

/*
*  Sets the reference color attribute
*  POST: refcolor is set to the supplied value
*/
void PriorityNeighbours::SetReferenceColor(HSLAPixel ref) {
  // complete your implementation below
  refcolor = ref;
}
