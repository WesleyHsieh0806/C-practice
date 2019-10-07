#include <iostream>
//遞迴練習
using namespace std;
//階層


int recursion(int );//先宣告一個回傳int的function





int main()

{

    int n=0;
    cout<<"Please input n to calculate n!(remind: n has to >0):";
    cin>>n;
    int result=recursion(n);
    if(n>=0)
    {
        cout<<result <<endl;
    }
    else if(n<0)
    {
        cout<<"n has  to >0 聽不懂人話逆!"<<endl;
    }



    return 0;
}

//這裡開始實際寫function
int recursion(int n)
{
    int result;
    if(n==1)
    {

        return 1;
    }
    else if(n>1)
    {
        result=n* recursion(n-1);
        return result;
    }
    else if(n<0)
    {
        return n;
    }

}
