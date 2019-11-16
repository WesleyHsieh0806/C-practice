#include <iostream> //500:34 5000(120)
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
int count =0;
int maxi=0;
int test=0;
void find(int ,int);
struct point
		{
			int p1;
			int p2;
		};
point chord;
//vector<point> in;
vector<point> out;
vector<point> tmp;
vector<vector<int> > judge;
vector<vector<int> > judgex;
vector<vector<int> > MIS;
vector<int> k(10000);
vector<int> monitor1(10000);
vector<int> monitor2(10000);
int main(int argc, char **argv)
{
	monitor1.resize(10000);
	monitor2.resize(10000);
	k.resize(10000);
	judge.resize(10000);
	judgex.resize(10000);
	MIS.resize(10000);
	for(int a=0 ;a!=10000; ++a )
	{
		judge[a].resize(10000);
		MIS[a].resize(10000);
		judgex[a].resize(10000);
	}
//
    if(argc != 3)
    {
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
        system("pause");
//        exit(1);
    }

    // open the input file
    fstream fin;
    fin.open(argv[1], fstream::in);
    if(!fin.is_open())
    {
        cout << "Error: the input file is not opened!!" << endl;
        exit(1);
    }

    // parse the input file
    cout << "======================" << endl;
    cout << "        Parser        " << endl;
    cout << "======================" << endl;

    char buffer[100];

    fin >> buffer;
    int numChord = atoi(buffer);

    cout << "#Chords:" << numChord << endl;
// program
    for(int s = 0; s < numChord / 2; ++s) // numChord / 2 =6
    {
    	fin >> buffer;
    	int point1 = atoi(buffer);
    	fin >> buffer;
    	int point2 = atoi(buffer);
    	cout << "Chord(" << point1 << "," << point2 << ")" << endl;
		//chord.p1=point1;
		//chord.p2=point2;
		//in.push_back(chord);//0~249
		for (int i= 0; i<=numChord-1 ; ++i)
			for(int j=0; j<=numChord-1 ; ++j)
			{
					if(j==point1)
				{
					k[j]=point2;
					if (k[j]<i || k[j]>j)
					{
							judge[i][j]=1;
					}

					else if(k[j]>i && k[j]<j)
					{
							judge[i][j]=2;
					}

					else if (k[j] == i)
					{
							judge[i][j]=3;
					}
				}
					if(j==point2)
				{
					k[j]=point1;
					if (k[j]<i || k[j]>j)
					{
							judge[i][j]=1;
					}

					else if(k[j]>i && k[j]<j)
					{
							judge[i][j]=2;
					}

					else if (k[j] == i)
					{
							judge[i][j]=3;
					}
				}


			}
	}
	for(int j= 1; j<=numChord-1 ; ++j)
	{
		for(int i=0; i<j ; ++i)
			{
				switch ( judge[i][j] )
				{
				case 1:
					MIS[i][j]=MIS[i][j-1];
					judgex[i][j]=1;
					break;
				case 2:
					MIS[i][j]=max( ( MIS[i][j-1] ), (MIS[i][k[j]-1] + 1 +MIS[k[j]+1][j-1])  );
					if(( MIS[i][j-1] ) > (MIS[i][k[j]-1] + 1 +MIS[k[j]+1][j-1]))
						judgex[i][j]=2;
					else
						judgex[i][j]=4;
					break;
				case 3:
					MIS[i][j]=MIS[i+1][j-1] + 1 ;
					judgex[i][j]=3;
					break;
				default:
					break;
				}
			}
	}
	int maxi=MIS[0][numChord-1];
	int a=0;
	int b=numChord-1;
	find(a,b);
	for(int i=0;i<tmp.size();++i)
		{

			find(tmp[i].p1 ,tmp[i].p2);
		}
 // open the output file
    fstream fout;
    fout.open(argv[2],fstream::out);
    if(!fout.is_open())
    {
        cout << "Error: the output file is not opened!!" << endl;
	    exit(1);
    }

    fout << "MIS(0 " << numChord-1 << "):"<< MIS[0][numChord-1] << "count:"<< count <<"test:"<< test<<endl;
	//for (int i=0;i<count;++i)
	//fout << "monitor: "<<monitor1[i] <<"," <<monitor2[i] <<"judgex:"<< judgex[monitor1[i]][monitor2[i]] <<endl;
	for(int i=0; i < out.size()-1 ; ++i)//0 1
	{
		for(int j=i+1 ; j<out.size() ; ++j )//i ~2
		{
			if(out[j].p1 < out[i].p1)
			swap(out[i] , out[j]);
		}
	}
	for(int i=0; i < out.size(); ++i)
	{
		fout << "Chord[" << i+1 <<"]=(" << out[i].p1 << "," << out[i].p2 << ")" << endl;
	}
    system("pause");
    return 0;
}
//.......................
void find(int i,int j)
	{
		while(i<j)

				{
				//	monitor1.push_back(i); //push back
				//	monitor2.push_back(j);
						switch ( judgex[i][j] )
							{
								case 1:
									test=1;
									j=j-1;
									break;
								case 2:
									test=2;
									j=j-1;
									break;
								case 3:
									chord.p1=i;
									chord.p2=j;
									out.push_back(chord); //vector sort
									count=count+1;
									i=i+1;
									j=j-1;
									test=3;
									break;
								case 4:
									chord.p1=k[j];
									chord.p2=j;
									out.push_back(chord); //vector sort
									count=count+1;
									chord.p1=i;
									chord.p2=k[j];
									tmp.push_back(chord); //vector sort
									i=k[j]+1;
									j= j-1; //first
									test=4;
									break;
								default:
									test=5;
									break;
							}
				}

		}



