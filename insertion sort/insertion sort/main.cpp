#include <iostream>
//�|���ѨM���D:�p��إߤ@�Ӥj�p�۰ʧ��ܯx�}�A�p��⥼���j�p�x�}�ǤJ���(��Template)
using namespace std;
//�w�]�wCTRL+X�O�ƪ�

template <typename T, size_t N>//T�N��ǤJ���O size_t�N��ǤJ�x�}�j�p
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

    for(int j=1; j<=5; j++) //�qj���e���@¾���e�䪽�����key�p�N���U�� �Y��key�j�N���k���@��
    {
        int key=a[j];//��a[j]�O�U��K���
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
