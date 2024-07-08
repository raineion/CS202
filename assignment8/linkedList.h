/*
 * name: Daniel Martinez Julio, CS 202 - summer II, assignment 8
 * description: this file contains the implementation of
 *              the linkedlist class using templates
 * input: none
 * output: none
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// create node class for linked lists
template <class T>
class NodeType
{
public:
  T info;         // `info` is the data in the node, and is a template to allow different data types
  NodeType *link; // `link` is a pointer to the next node in the linked list
};

// class prototype using a template
template <class T>
class LinkedList
{
public:
  NodeType<T> *head, *tail; // `head` is a pointer to the first node, `tail` is a pointer to the last node

  int count; // `count` keeps track of the number of elements in the linked list

  // default constructor
  LinkedList();

  // function to determine whether the linked list is empty or not
  bool isEmpty();

  // function to return the number of elements in the list
  int listLength();

  // function to delete all the nodes in the list
  void destroyList();

  // function to return the `info` of the first node of the list
  T firstNodeInfo();

  // function to return the `info` of the last node of the list
  T lastNodeInfo();

  // function to add a new node to the end of the list
  void insertNodeAtEnd(T info);

  // function to delete a node from the beginning of the linked list
  void deleteFirstNode();

  // function to print the elements of the linked list
  void print();

  // function to create a deep copy of the linked list
  void makeCopy(const LinkedList<T> &otherList);
};

// implement member functions
// you get the first one for free!

// default constructor of linked list
template <class T>
LinkedList<T>::LinkedList()
{
  count = 0;      // initialize count to 0 since the list is empty
  head = nullptr; // initialize head to nullptr since the list is empty
  tail = nullptr; // initialize tail to nullptr since the list is empty
}

/*
 * isEmpty
 * description: function to check if the list is empty
 * input: none
 * output: returns true if the list is empty, otherwise false
 */
template <class T>
bool LinkedList<T>::isEmpty()
{
  return head == nullptr; // check if head is nullptr, meaning the list is empty
}

/*
 * listLength
 * description: function to return the number of elements in the list
 * input: none
 * output: returns the number of elements in the list
 */
template <class T>
int LinkedList<T>::listLength()
{
  return count; // return the number of elements in the list
}

/*
 * destroyList
 * description: function to delete all nodes in the list
 * input: none
 * output: none
 */
template <class T>
void LinkedList<T>::destroyList()
{
  NodeType<T> *temp;      // temporary pointer to hold the node to be deleted
  while (head != nullptr) // loop until the list is empty
  {
    temp = head;       // set temp to the current head
    head = head->link; // move head to the next node
    delete temp;       // delete the old head
  }
  tail = nullptr; // set tail to nullptr since the list is now empty
  count = 0;      // reset the count to 0
}

/*
 * firstNodeInfo
 * description: function to return the info of the first node
 * input: none
 * output: returns the info of the first node
 */
template <class T>
T LinkedList<T>::firstNodeInfo()
{
  if (head != nullptr) // check if the list is not empty
  {
    return head->info; // return the info of the first node
  }
}

/*
 * lastNodeInfo
 * description: function to return the info of the last node
 * input: none
 * output: returns the info of the last node
 */
template <class T>
T LinkedList<T>::lastNodeInfo()
{
  if (tail != nullptr) // check if the list is not empty
  {
    return tail->info; // return the info of the last node
  }
}

/*
 * insertNodeAtEnd
 * description: function to insert a new node at the end
 * input: t info - the data to insert in the new node
 * output: none
 */
template <class T>
void LinkedList<T>::insertNodeAtEnd(T info)
{
  NodeType<T> *newNode = new NodeType<T>; // create a new node
  newNode->info = info;                   // set the info of the new node
  newNode->link = nullptr;                // set the link of the new node to nullptr
  if (head == nullptr)                    // check if the list is empty
  {
    head = newNode; // set head to the new node
    tail = newNode; // set tail to the new node
  }
  else
  {
    tail->link = newNode; // link the current tail to the new node
    tail = newNode;       // update the tail to the new node
  }
  count++; // increment the count of elements in the list
}

/*
 * deleteFirstNode
 * description: function to delete the first node
 * input: none
 * output: none
 */
template <class T>
void LinkedList<T>::deleteFirstNode()
{
  if (head != nullptr) // check if the list is not empty
  {
    NodeType<T> *temp = head; // set temp to the current head
    head = head->link;        // move head to the next node
    delete temp;              // delete the old head
    count--;                  // decrement the count of elements in the list
    if (head == nullptr)      // check if the list is now empty
    {
      tail = nullptr; // set tail to nullptr since the list is now empty
    }
  }
  else
  {
  }

  /*
   * print
   * description: function to print the elements of the list
   * input: none
   * output: none
   */
  template <class T>
  void LinkedList<T>::print()
  {
    NodeType<T> *current = head; // set current to the head of the list
    while (current != nullptr)   // loop through the list
    {
      std::cout << current->info << " "; // print the info of the current node
      current = current->link;           // move to the next node
    }
    std::cout << std::endl; // print a newline at the end
  }

  /*
   * makeCopy
   * description: function to create a deep copy of the list
   * input: const linkedlist<t>& otherlist - the list to copy
   * output: none
   */
  template <class T>
  void LinkedList<T>::makeCopy(const LinkedList<T> &otherList)
  {
    if (this != &otherList) // check for self-assignment
    {
      destroyList();                 // delete any existing nodes on the current object
      if (otherList.head == nullptr) // check if the other list is empty
      {
        head = nullptr; // set head to nullptr since the other list is empty
        tail = nullptr; // set tail to nullptr since the other list is empty
        count = 0;      // set count to 0 since the other list is empty
      }
      else
      {
        NodeType<T> *current = otherList.head; // set current to the head of the other list
        while (current != nullptr)             // loop through the other list
        {
          insertNodeAtEnd(current->info); // insert a copy of the current node at the end of the current list
          current = current->link;        // move to the next node in the other list
        }
      }
    }
  }

#endif
