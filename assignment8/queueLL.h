/*
 * name: daniel martinez julio, cs 202 - summer ii, assignment 8
 * description: this file contains the implementation of
 *              the queueLL class using templates
 * input: none
 * output: none
 */

#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>
#include <string>
#include "linkedList.h"
#include "queueADT.h"

template <class T>
class QueueLL : public QueueADT<T>
{
private:
  LinkedList<T> myLL;  // an instance of the linked list to hold the queue elements

public:
  // function to initialize queue
  void initializeQueue();
  // this function doesn't need to perform any action, but it must be defined
  // to fulfill the requirements of the queueADT interface

  // function that determines if the queue is empty or not
  bool isEmpty();
  // this function checks if the queue (linked list) is empty by using the
  // isEmpty function of the linked list class

  // function that determines if the queue is full or not
  bool isFull();
  // this function always returns false because a linked list-based queue
  // can dynamically grow and never be full

  // function that returns the first element of the queue
  T firstElement();
  // this function returns the first element of the queue by using the
  // firstNodeInfo function of the linked list class

  // function that returns the last element of the queue
  T lastElement();
  // this function returns the last element of the queue by using the
  // lastNodeInfo function of the linked list class

  // function that adds an element to the end of the queue
  void addElement(const T &newItem);
  // this function adds a new element to the end of the queue by using the
  // insertNodeAtEnd function of the linked list class

  // function that removes the first element from the queue
  void deleteElement();
  // this function removes the first element from the queue by using the
  // deleteFirstNode function of the linked list class

  // function that prints all of the queue elements to std::cout
  void print();
  // this function prints all the elements of the queue by using the
  // print function of the linked list class

  // destructor
  ~QueueLL();
  // the destructor uses the destroyList function of the linked list class
  // to delete all nodes and free the memory

  // overloaded assignment operator
  const QueueLL<T> &operator=(const QueueLL<T> &otherQueue);
  // this function overloads the assignment operator to allow deep copying
  // of the queue by copying each element from the other queue

  // copy constructor
  QueueLL(const QueueLL<T> &otherQueue);
  // this function allows creation of a new queue as a copy of another queue
  // by copying each element from the other queue

  // default constructor
  QueueLL();
  // this function doesn't need to perform any action, it just needs to be defined
};

// implement member functions
// you get the first one for free!

/*
 * initializeQueue
 * description: function to initialize the queue
 * input: none
 * output: none
 */
template <class T>
void QueueLL<T>::initializeQueue()
{
  // don't do anything
  // this function is required by the interface but doesn't need to perform any action
}

/*
 * isEmpty
 * description: function to determine if the queue is empty
 * input: none
 * output: returns true if the queue is empty, otherwise false
 */
template <class T>
bool QueueLL<T>::isEmpty()
{
  return myLL.isEmpty();  // call the isEmpty function of the linked list to check if the queue is empty
}

/*
 * isFull
 * description: function to determine if the queue is full
 * input: none
 * output: returns false, as our linked list is never full
 */
template <class T>
bool QueueLL<T>::isFull()
{
  return false;  // return false because a linked list can always grow and never be full
}

/*
 * firstElement
 * description: function to return the first element of the queue
 * input: none
 * output: returns the first element of the queue
 */
template <class T>
T QueueLL<T>::firstElement()
{
  return myLL.firstNodeInfo();  // call the firstNodeInfo function of the linked list to get the first element
}

/*
 * lastElement
 * description: function to return the last element of the queue
 * input: none
 * output: returns the last element of the queue
 */
template <class T>
T QueueLL<T>::lastElement()
{
  return myLL.lastNodeInfo();  // call the lastNodeInfo function of the linked list to get the last element
}

/*
 * addElement
 * description: function to add an element to the end of the queue
 * input: const t& newitem - the new element to add
 * output: none
 */
template <class T>
void QueueLL<T>::addElement(const T &newItem)
{
  myLL.insertNodeAtEnd(newItem);  // call the insertNodeAtEnd function of the linked list to add the new element to the end of the queue
}

/*
 * deleteElement
 * description: function to remove the first element from the queue
 * input: none
 * output: none
 */
template <class T>
void QueueLL<T>::deleteElement()
{
  myLL.deleteFirstNode();  // call the deleteFirstNode function of the linked list to remove the first element from the queue
}

/*
 * print
 * description: function to print all the elements of the queue
 * input: none
 * output: none
 */
template <class T>
void QueueLL<T>::print()
{
  myLL.print();  // call the print function of the linked list to print all the elements of the queue
}

/*
 * ~QueueLL
 * description: destructor for the queueLL class
 * input: none
 * output: none
 */
template <class T>
QueueLL<T>::~QueueLL()
{
  myLL.destroyList();  // call the destroyList function of the linked list to delete all nodes and free the memory
}

/*
 * operator=
 * description: overloaded assignment operator
 * input: const queueLL<t>& otherqueue - the queue to copy
 * output: returns the assigned queueLL object
 */
template <class T>
const QueueLL<T> &QueueLL<T>::operator=(const QueueLL<T> &otherQueue)
{
  if (this != &otherQueue)  // check for self-assignment to avoid copying the same object
  {
    myLL.destroyList();  // destroy the current list to avoid memory leaks
    myLL.makeCopy(otherQueue.myLL);  // make a deep copy of the other queue's linked list
  }
  return *this;  // return the current object to allow chaining of assignment
}

/*
 * QueueLL
 * description: copy constructor for the queueLL class
 * input: const queueLL<t>& otherqueue - the queue to copy
 * output: none
 */
template <class T>
QueueLL<T>::QueueLL(const QueueLL<T> &otherQueue)
{
  myLL.makeCopy(otherQueue.myLL);  // make a deep copy of the other queue's linked list
}

/*
 * QueueLL
 * description: default constructor for the queueLL class
 * input: none
 * output: none
 */
template <class T>
QueueLL<T>::QueueLL()
{
  // don't do anything
  // this constructor doesn't need to perform any action, it just needs to be defined
}

#endif
