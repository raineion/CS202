/*
  DO NOT EDIT
*/

#include <iostream>
#include <cassert>
#include <string>
#include <cmath>
#include "queueLL.h"

using namespace std;

// global function for testing closeness of floating point numbers
bool isclose(double d1, double d2, double atol=1e-5, double rtol=1e-5) {
  // absolute tolerance test
  if (fabs(d1 - d2) < atol) {
    // relative tolerance test
    // skip if we're close to 0 to avoid division by 0
    if (fabs(d1) < rtol) {
      return true;
    } else if (fabs(d1 - d2) / fabs(d1) < rtol) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

int main() {
  // make a new linked list-based queue
  QueueLL<int> myQueue;
  myQueue.initializeQueue();

  // run some basic tests on it
  assert(myQueue.isEmpty());
  myQueue.addElement(7);
  assert(!myQueue.isEmpty());
  myQueue.addElement(17);
  myQueue.addElement(-1);
  myQueue.addElement(12);
  assert(myQueue.firstElement() == 7);
  assert(myQueue.lastElement() == 12);
  assert(!myQueue.isFull());
  myQueue.print();
  myQueue.deleteElement();
  assert(myQueue.firstElement() == 17);

  // try a different type of queue
  QueueLL<double> myQueue2;
  myQueue2.initializeQueue();

  assert(myQueue2.isEmpty());
  myQueue2.addElement(-1.5);
  assert(!myQueue2.isEmpty());
  myQueue2.addElement(0.75);
  myQueue2.addElement(3.125);
  myQueue2.addElement(-2.75);
  assert(isclose(myQueue2.firstElement(), -1.5));
  assert(isclose(myQueue2.lastElement(), -2.75));
  assert(!myQueue2.isFull());
  myQueue2.deleteElement();
  assert(isclose(myQueue2.firstElement(), 0.75));

  // use assignment operator to copy queue
  QueueLL<double> myQueue3 = myQueue2;
  // make sure they have similar attributes
  assert(isclose(myQueue2.firstElement(), myQueue3.firstElement()));
  assert(isclose(myQueue2.lastElement(), myQueue3.lastElement()));
  assert(!myQueue2.isEmpty());
  assert(!myQueue3.isEmpty());
  // make sure we didn't do a shallow/lazy copy
  myQueue3.deleteElement();
  assert(!isclose(myQueue3.firstElement(), myQueue2.firstElement()));
  assert(isclose(myQueue3.firstElement(), 3.125));
  assert(isclose(myQueue2.firstElement(), 0.75));
  assert(isclose(myQueue2.lastElement(), myQueue3.lastElement()));
  // clean the queue out
  while (!myQueue3.isEmpty()) {
    myQueue3.deleteElement();
  }
  // make sure myQueue2 is not empty
  assert(!myQueue2.isEmpty());

  // use copy constructor
  QueueLL<double> myQueue4(myQueue2);

  // same rigmarole
  assert(isclose(myQueue2.firstElement(), myQueue4.firstElement()));
  assert(isclose(myQueue2.lastElement(), myQueue4.lastElement()));
  assert(!myQueue2.isEmpty());
  assert(!myQueue4.isEmpty());
  myQueue4.deleteElement();
  assert(!isclose(myQueue4.firstElement(), myQueue2.firstElement()));
  assert(isclose(myQueue4.firstElement(), 3.125));
  assert(isclose(myQueue2.firstElement(), 0.75));
  while (!myQueue4.isEmpty()) {
    myQueue4.deleteElement();
  }
  assert(!myQueue2.isEmpty());

  // try adding lots of elements to make sure we don't leak memory
  while (!myQueue.isEmpty()) {
    myQueue.deleteElement();
  }
  for (int i=0; i<1000; i++) {
    myQueue.addElement(i);
    assert(!myQueue.isFull());
  }
  assert(myQueue.firstElement() == 0);
  assert(myQueue.lastElement() == 999);

  cout << "All tests successfully passed!" << endl;
  return 0;
}
