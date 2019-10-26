// **************************************************************************
//  File       [main.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The main program of 2019 fall Algorithm PA1]
//  Modify     [2019/9/6 Cheng-Yun Hsieh]
// **************************************************************************

#include <cstring>
#include <iostream>
#include <fstream> //有這個才能用fstream
#include "../lib/tm_usage.h"
#include "sort_tool.h"

using namespace std;

void help_message() {
    cout << "usage: NTU_sort -[IS|MS|QS|HS] <input_file> <output_file>" << endl;
    cout << "options:" << endl;
    cout << "   IS - Insersion Sort" << endl;
    cout << "   MS - Merge Sort" << endl;
    cout << "   QS - Quick Sort" << endl;
    cout << "   HS - Heap Sort" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 4) {
       help_message();
       return 0;
    }
    CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;

    //////////// read the input file /////////////
    
    char buffer[200];
    fstream fin(argv[2]);//設一個fstream 叫做fin的file 並把argv矩陣的第3項傳入
    //fstream 是一個用來將資料輸入輸出的class
    fstream fout;
    fout.open(argv[3],ios::out);//在輸出模式下開啟argv[3]
    fin.getline(buffer,200);//getline 讀取buffer 
    fin.getline(buffer,200);
    int junk,num;
    vector<int> data;
    while (fin >> junk >> num)
        data.push_back(num); // data[0] will be the first data. 
                             // data[1] will be the second data and so on.
    
    //////////// the sorting part ////////////////
    tmusg.periodStart();
    SortTool NTUSortTool; 
//strcmp比較兩字串 若相同回傳0
    if(!strcmp(argv[1],"-QS")) {
        NTUSortTool.QuickSort(data);
    }
    else if(!strcmp(argv[1],"-IS")) {
        NTUSortTool.InsertionSort(data);
    }
    else if(!strcmp(argv[1],"-MS")) {
        NTUSortTool.MergeSort(data);
    }
    else if(!strcmp(argv[1],"-HS")) {
        NTUSortTool.HeapSort(data);
    }
    else {
        help_message();
        return 0;
    }//這一區決定要做哪個sorting

    tmusg.getPeriodUsage(stat);
    cout <<"The total CPU time: " << (stat.uTime + stat.sTime) / 1000.0 << "ms" << endl;
    cout <<"memory: " << stat.vmPeak << "KB" << endl; // print peak memory

    //////////// write the output file ///////////
    fout << "# " << data.size() << " data points" <<endl;
    fout << "# index number" << endl;
    for (int i = 0; i < data.size(); i++)
        fout << i << " " <<data[i] << endl;
    fin.close();//fstream開檔案之後要關掉
    fout.close();
    return 0;
}
