#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    //��char�G�L�}�C��{string_array
    char str1 [4][10]={"Hi","I'm","Wesley","yo"} ;
    for (int i=0; i<4; i++)
    {
        cout<<str1[i]<<" ";
    }
    cout<<endl;
//char���Ы��V�@�Ӧr��
    char c[6]={'H','E','L','L','O'};
    char *str5=&c[0];
    cout<<str5<<endl;
    cout<<*(str5+2)<<endl;

    //char���а}�C��{�G���}�C
    //�C�ӫ��Ы��V�r��
    char *str4[2]={"Hello world","Hi"};
    cout<<str4[0]+2;
    cout<<endl;
//��string��{stringarray

    string str2[4]={"Hi"};
    cout<<endl;
    for (int i=0; i<4; i++)
    {
        str2[i].assign(str1[i]);
        cout<<str2[i]<<" ";
    }
    cout<<endl;
//��stringtype��vector��{string array

    vector<string> str3;
    for (int i=0; i<4; i++)
    {
        str3.push_back(str1[i]);
        cout<<str3[i]<<" ";
    }

    return 0;
}
