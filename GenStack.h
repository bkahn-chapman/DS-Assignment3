/*
* Name: Benjamin Kahn
* ID: 2316793
* Class: CPSC-350-01
* Assignment: Programming Assignment 3: Syntax Checker
* About: GenStack.h is a template class for a generic stack.
*/

#include <iostream>
#include <string>
using namespace std;

template <class T>
class GenStack
{
  public:
    GenStack();
    GenStack(int maxSize);
    ~GenStack();

    void push(char data);
    char pop();
    bool isFull();
    bool isEmpty();
    char peek();
    void enlarge();
    int getSize();

    int size;
    int top;

    T *myArray;
    T *tempArray;
};

template <class T>
GenStack<T>::GenStack()
{
  T *myArray = new T[256];
  size = 256;
  top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize)
{
  T *myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack()
{
  cout << "The stack was deleted." << endl;
}

template <class T>
void GenStack<T>::push(char data)
{
  if(isFull())
  {
    enlarge();
  }
  myArray[++top] = data;
}

template <class T>
char GenStack<T>::pop()
{
  if(!isEmpty())
  {
    return myArray[top--];
  }
}

template <class T>
char GenStack<T>::peek()
{
  if(!isEmpty())
  {
    return myArray[top];
  }
}

template <class T>
bool GenStack<T>::isFull()
{
  return (top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}

template <class T>
void GenStack<T>::enlarge()
{
    T *tempArray = new T[size*2];
    for(int i = 0; i < size; ++i)
    {
      tempArray[i] = myArray[i];
    }
    delete myArray;
    T *myArray = new T[size*2];
    for(int i = 0; i < size; ++i)
    {
      myArray[i] = tempArray[i];
    }
    delete tempArray;
    size = size * 2;
}

template <class T>
int GenStack<T>::getSize()
{
  return(top+1);
}
