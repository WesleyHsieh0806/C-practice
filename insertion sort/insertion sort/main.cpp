#include <iostream>
//尚未解決問題:如何建立一個大小自動改變矩陣，如何把未知大小矩陣傳入函數(用Template)
using namespace std;
//已設定CTRL+X是排版

template <typename T, size_t N>//T代表傳入型別 size_t代表傳入矩陣大小
void coutarray(T (&arr)[N])
{
    for(size_t i = 0; i < N; ++i)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int a[6];

    cout<<"Please input six number to be insertion sorted:";
    for(int i=0; i<=5; i++)
    {
        cin>>a[i];
    }

    for(int j=1; j<=5; j++) //從j的前面一職網前找直到找到比key小就停下來 若比key大就往右邊丟一格
    {
        int key=a[j];//把a[j]記下方便比較
        int i=j-1;
        while(a[i]>key &&i>=0)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;

    }

    coutarray(a);
}
