#ifndef Sort_Compare_hpp
#define Sort_Compare_hpp

#include <stdio.h>
#include <iostream>
#include "Sequence.hpp"




int compare_int(const void *arg1, const void *arg2);
int compare_double(const void *arg1, const void *arg2);

template <typename T>
void swap(T* a, T* b);

template <class T>
void selectionSort(Sequence<T>* a);

template <class T>
int findSmallestPosition(Sequence<T>* a, int startPosition, int listLength);


template <class T>
void shellSort(Sequence<T>* a);

template <typename T>
int test_sort(Sequence<T> * seq);

template <typename T>
void BubbleSort(Sequence<T>* a);

template <class T>
void BubbleSortDown(Sequence<T>* a);




int compare_int(const void *arg1, const void *arg2)
{
    int val1 = *(const int*) arg1; // требуется явное преобразование из const void * в const int *
    int val2 = *(const int*) arg2;
    if (val1 < val2)
        return -1;
    else
        return val1 > val2;
}

int compare_double(const void *arg1, const void *arg2)
{
    int val1 = *(const double*) arg1;
    int val2 = *(const double*) arg2;
    if (val1 < val2)
        return -1;
    else
        return val1 > val2;
}


template <class T>
void swap(T* a, T* b)
{
    T k = *a;
    *a = *b;
    *b = k;
}



template <class T>
int findSmallestPosition(Sequence<T>* a, int startPosition, int listLength)
{
    int smallestPosition = startPosition;

    for (int i = startPosition; i < listLength; i++)
    {
        if (a -> Get_(i) < a -> Get_(smallestPosition))
        smallestPosition = i;
    }
    return smallestPosition;
}

template <class T>
void selectionSort(Sequence<T>* a)
{
    for (int i = 0; i < a -> GetLength_(); i++)
    {
        int smallestPosition = findSmallestPosition(a, i, a -> GetLength_());
        swap((a -> Getadress_(i)), (a -> Getadress_(smallestPosition)));
    }
}

template <class T>
void shellSort(Sequence<T>* a)
{
    int n = a -> GetLength_();
    int d = n;
    d = d / 2;

    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i;
            while (j >= 0 && a ->Get_(j) > a -> Get_(j + d))
            {
                T count = a -> Get_(j);
                a -> Set_(a -> Get_(j + d),j) ;
                a -> Set_(count, j + d);
                j--;
            }
        }
        d = d / 2;
    }
}

template <class T>
void BubbleSort(Sequence<T>* a)
{
    
    for (int i = 0; i < a -> GetLength_(); i++)
    {
        for (int j = 0; j < a -> GetLength_() - 1; j++)
        {
          if (a->Get_(j) > a->Get_(j + 1))
          {
            T b = a->Get_(j);
            a->Set_(a->Get_(j + 1), j);
            a->Set_(b, j+1);
          }
        
        }
      }
}



template <class T>
void BubbleSortDown(Sequence<T>* a)
{
    
    for (int i =  a -> GetLength_()-1; i >= 0; i--)
    {
        for (int j = a -> GetLength_() - 1; j >=1; j--)
        {
          if (a->Get_(j) > a->Get_(j - 1))
          {
            T b = a->Get_(j);
              
            a->Set_(a->Get_(j - 1), j);
              //int k=j+1;
            a->Set_(b, j-1); 
          }
        
        }
      }
}








template <typename T>
int test_sort(Sequence<T> * seq)
{
    cout<<"Checking the correctness of the sorting!";
    int er = 0;
    for (int i = 0; i < seq->GetLength_()-1; i++)
        if (seq->Get_(i) > seq->Get_(i+1))
            er++;
    cout<<" number of errors = "<< er <<endl;
    if (er == 0)
        cout<<"The test of correctness of the conducted sorting was passed without errors"<< endl;
    else
        cout<<"The test of the correctness of the sorting was not passed"<< endl;
    return er;
    
}







#endif /* Sort_Compare_hpp */
