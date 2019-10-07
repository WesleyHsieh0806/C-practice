#include<iostream>
using namespace std;

void swap(int *currentminimun,int *newminimun)
{
    int minimun=*currentminimun;
    *currentminimun=*newminimun;
    *newminimun=minimun;




}
int main()
{
    int a[5];
    cout<<"Please input five numbers to complete selection sort:" ;
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
    for (int i=0; i<4; i++)
    {
        int  minin=i;
        for(int j=i+1; j<5; j++)//記得要從i+1開始比不然又要重新比一次會把前面小的吸
        {
            if(a[minin]>a[j])
            {
                minin=j;


            }



        } swap(&a[i],&a[minin]);


    }

    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<" ";



    }



return 0;
}
