// **************************************************************************
//  File       [main.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The main program of 2019 fall Algorithm PA1]
//  Modify     [2019/9/6 Cheng-Yun Hsieh]
// **************************************************************************

#include <cstring>
#include <iostream>
#include <fstream> //���o�Ӥ~���fstream
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
    fstream fin(argv[2]);//�]�@��fstream �s��fin��file �ç�argv�x�}����3���ǤJ
    //fstream �O�@�ӥΨӱN��ƿ�J��X��class
    fstream fout;
    fout.open(argv[3],ios::out);//�b��X�Ҧ��U�}��argv[3]
    fin.getline(buffer,200);//getline Ū��buffer 
    fin.getline(buffer,200);
    int junk,num;
    vector<int> data;
    while (fin >> junk >> num)
        data.push_back(num); // data[0] will be the first data. 
                             // data[1] will be the second data and so on.
    
    //////////// the sorting part ////////////////
    tmusg.periodStart();
    SortTool NTUSortTool; 
//strcmp�����r�� �Y�ۦP�^��0
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
    }//�o�@�ϨM�w�n������sorting

    tmusg.getPeriodUsage(stat);
    cout <<"The total CPU time: " << (stat.uTime + stat.sTime) / 1000.0 << "ms" << endl;
    cout <<"memory: " << stat.vmPeak << "KB" << endl; // print peak memory

    //////////// write the output file ///////////
    fout << "# " << data.size() << " data points" <<endl;
    fout << "# index number" << endl;
    for (int i = 0; i < data.size(); i++)
        fout << i << " " <<data[i] << endl;
    fin.close();//fstream�}�ɮפ���n����
    fout.close();
    return 0;
}
