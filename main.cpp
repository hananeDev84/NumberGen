/* numberGen.cpp : program that generate an amount of random number and stores them in array after partial sorting, decreasing order sort and completely unsorted.
it thereby use some data structures algorithm such as selection sort, insertion sort, merge sort, quicksort and heap sort to identify their efficiency*/ 
//by Abdoul hanane Gbadmassi on 4/26/2020

#include <iostream>
#include<fstream>
#include <stdlib.h> 
#include <time.h>
#include <algorithm>
#include"Sorting.h"

int numsize=0;
void setsize(int & n)
{
  numsize = n;
  
}
using namespace std;
void createFile(){
    ofstream push;
    int p, i = 0;
    int n;
    push.open("text.txt", ios::out);
    cout << "how many randum number did you want to generate?" << endl;
    cin >> n;
    setsize(n);
    while (i < n)
    {
        p = rand() % n;
        push << p << " ";
        i++;
    }
    push.close();
}
void putnumArray(int* array)
{
    ifstream put;
    put.open("text.txt", ios::in);
    int i = 0;
    while (!put.eof())
    {
        put >> array[i];
        i++;
    }
    put.close();
    
}

void printArray(int *array)
{
  for (int i = 0; i < numsize; i++)
    {   
        cout << array[i] << " " ;
        
    }
}

int main()
{
    createFile();
    
    int j;
    ofstream push;
    
    int* a_sorted= new int[numsize];
    int* d_sorted= new int[numsize];
    int* c_unsorted = new int[numsize];
    putnumArray(a_sorted);
    sort(a_sorted, a_sorted + numsize*90/100);
    
    cout << "almost sorted" << endl;
    printArray(a_sorted);
    push.open("a_text.txt", ios::out);
    for (int i = 0; i < numsize; i++)
       push<< a_sorted[i] << " " ;
  
   
    cout << endl;
    push.close();
    //insertionSort(a_sorted, numsize);
    //selectionSort(a_sorted, numsize);
    //mergeSort(a_sorted,0,numsize-1);
    //quickSort(a_sorted,0,numsize-1);
    heapSort(a_sorted, numsize);
       print(); //print the swap and the comparisons numbers 
       reset(); // set the counter to 0
    cout<<endl<<"after Sorting"<<endl;
     printArray(a_sorted);
    cout<< endl;
    putnumArray(d_sorted);
   
    sort(d_sorted, d_sorted + numsize, greater<int>());
    cout << "descending order sorted" << endl;
    push.open("d_text.txt", ios::out);
    for (int i = 0; i < numsize; i++)
    {   
        cout << d_sorted[i] << " " ;
        push<<d_sorted[i] << " ";
    }
    cout << endl;
    push.close();

    //insertionSort(d_sorted, numsize);
    //selectionSort(d_sorted, numsize);
    //mergeSort(d_sorted,0,numsize-1);
    //quickSort(d_sorted,0,numsize-1);
    heapSort(d_sorted, numsize);
      print(); //print the swap and the comparisons numbers
      reset(); // set the counter to 0
    cout<<endl<<"after Sorting"<<endl;
    for (int i = 0; i < numsize; i++)
    {   
        cout << d_sorted[i] << " " ;
        
    }
    cout<< endl;
    putnumArray (c_unsorted);
    cout << "completely unsorted" << endl;
    for (int i = 0; i < numsize; i++)
    {
        cout << c_unsorted[i] << " " ;
    }
    cout << endl;
    push.close();
    //insertionSort(c_unsorted, numsize);
    //selectionSort(c_unsorted, numsize);
    //mergeSort(c_unsorted,0,numsize-1);
    //quickSort(c_unsorted,0,numsize-1);
    heapSort(c_unsorted, numsize);
      print();//print the swap and the comparisons numbers
      reset();// set the counter to 0
    cout<<endl<<"after Sorting"<<endl;
    for (int i = 0; i < numsize; i++)
    {   
        cout << c_unsorted[i] << " " ;
        
    }


//delete the memory allocation
delete [] a_sorted;
delete [] d_sorted;
delete [] c_unsorted;
}



