// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2019/9/6 Cheng-Yun Hsieh]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
  void SortTool::InsertionSort(vector<int>& data) {
       // Function : Insertion sort
       // TODO : Please complete insertion sort code here
       int i;
   
       for(i=1 ;i<data.size() ;i++)
       { int key=data[i];
    
       int j=i-1;
     while(j>=0&&data[j]>key)
     {data[j+1]=data[j];
     
       j--;
     }
        
       data[j+1]=key;
                         }
   }

// Quick sort method
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
}

int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    // Hint : Textbook page 171
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    int middle=0;
    if(low<high){  middle=(low + high )/2 ;      
   
    MergeSortSubVector(data,low,middle);
    MergeSortSubVector(data,middle+1,high);
    Merge(data,low,middle,middle+1,high);}
  
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    vector<int> L(data.begin()+low,data.begin()+middle1+1);//迭代會把最後一個設定成為end也就是空的 所以要多一個
    vector<int> R(data.begin()+middle2,data.begin()+high+1);
    L.push_back(20000000);//指數的用法要注意不是用^
    R.push_back(20000000);
 

    int j=0;
    int k=0;
    for(int i=low;i<=high;i++)
    {
      if(R[k]<L[j])
        {data[i]=R[k];
          k++;
    
          }
      else{
          data[i]=L[j];
          j++;
      }    
    }
    
    
    
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
}
