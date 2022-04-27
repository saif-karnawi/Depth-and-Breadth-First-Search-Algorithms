/*
* File:        testStackQueue.cpp
* Description: Basic test cases for CPSC 221 2021W2 PA2 - Stack and Queue
*              Add your own code to this!
*
* Date:        2022-02-11 00:37
*
*/

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "cs221util/catch.hpp"

#include "stack.h"
#include "queue.h"

using namespace std;

TEST_CASE("Stack::basic functions", "[weight=1][part=stack]") {
  cout << "Testing Stack..." << endl;
  Stack<int> intStack;
  
  for(int i = 0; i < 256; i++) {
    intStack.Push(i);
  }

  cout << intStack.Capacity() << endl;
  for(int i = 0; i < 256; i++) {
    cout << intStack.Pop() << endl;
  }

  // vector<int> result;
  // vector<int> expected;
  // for (int i = 10; i > 0; i--) {
  //   expected.push_back(i);
  // }
  // for (int i = 1; i <= 10; i++) {
  //   intStack.Push(i);
  // }
  // //cout << intStack.peek() << endl;
  // while (!intStack.IsEmpty()) {
  //   result.push_back(intStack.Pop());
  //   //cout << intStack.pop() << " ";
  // }
  // REQUIRE(result == expected);
}
TEST_CASE("Queue::basic functions", "[weight=1][part=queue]") {
  cout << "Testing Queue..." << endl;
  Queue<int> intQueue;
  vector<int> result;
  vector<int> expected;

  intQueue.Enqueue(1);
  intQueue.Enqueue(2);

  cout<< intQueue.Peek()<< endl;

  int s = intQueue.Dequeue();
  int f = intQueue.Dequeue();


  for (int i = 1; i <= 10; i++) {
    expected.push_back(i);
  }
  for (int i = 1; i <= 10; i++) {
    intQueue.Enqueue(i);
  }
  //cout << intStack.peek() << endl;
  while (!intQueue.IsEmpty()) {
    result.push_back(intQueue.Dequeue());
    //cout << intStack.pop() << " ";
  }
  REQUIRE(result == expected);
}

