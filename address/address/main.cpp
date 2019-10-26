#include <iostream>

using namespace std;

int main()
{
//   int a=13;
//   int b=a;
//   int *p_a;
//   p_a=&a;
//   int *p_b;
//   p_b=&b;
//   cout<<p_a<<endl;
//   cout<<p_b<<endl;
//   cout<<p_a<<" is different with "<< p_b<<endl;//C++的cout真猛 python要print若要用+號必須要DATA TYPE相同

   int x=1;
   while(x<10){
    if(x==1){x+=10;
    cout<<"case1 x:"<<x<<endl;}
    else if(x==2){
        x+=10;
        cout<<"case2 x:"<<x<<endl;
    }

    cout<<"case3 x:"<<x<<endl;
    x+=5;

   }
}
