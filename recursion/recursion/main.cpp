#include <iostream>
//���j�m��
using namespace std;
//���h


int recursion(int );//���ŧi�@�Ӧ^��int��function





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
        cout<<"n has  to >0 ť�����H�ܰf!"<<endl;
    }



    return 0;
}

//�o�̶}�l��ڼgfunction
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
