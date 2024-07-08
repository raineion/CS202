#ifndef QUEUEADT_H
#define QUEUEADT_H

template <class T>
class QueueADT {
  // function to initialize a queue
  virtual void initializeQueue() = 0;
  // After constructing a queue, this function should be called to set it to a
  // default state,

  // function that determines if the queue is empty or not
  virtual bool isEmpty() = 0;
  // Should return `true` if the queue has zero elements in it and `false`
  // otherwise.

  // function that determines if the queue is full or not
  virtual bool isFull() = 0;
  // Should return `true` if no more elements can be added to the queue and
  // `false` otherwise.

  // function that returns the first element in the queue
  virtual T firstElement() = 0;
  // It does not consume the element from the queue (i.e., the state of the
  // queue should be the same after calling this function).

  // function that returns the last element in the queue
  virtual T lastElement() = 0;
  // It does not consume the element from the queue (i.e., the state of the
  // queue should be the same after calling this function).

  // function that adds an element to the end of the queue
  virtual void addElement(const T& newItem) = 0;
  // Note: this function does not have to check whether elements can be added
  // or not, as we assume/check the queue is not full before calling this
  // function.

  // function that removes the first element from the queue
  virtual void deleteElement() = 0;
  // Note: this function does not have to check that the queue is not empty, as
  // we assume/check that it's not empty before calling this function.

  // function that prints all of the elements of our queue to std::cout.
  virtual void print() = 0;
};

#endif
