#include <iostream>

using namespace std;
// pointer �Ϊk �ܼƧΦ�*�ܼƦW�� �ܼƦW��=&�t�@���ܼƦW��
int main()

{
    int a =4016;
    int *ptr_a;
    int* ptr2_a;
    //int* p�i����p�O�@��int pointer , int *p �h�O��*p�O�@�Ӿ��
    ptr_a=&a;
    ptr2_a=&a;

    cout<<"The value of a is: "<<a<<endl;
    cout<<"The address of a is: "<<ptr_a<<endl;
    cout<<"The address of a is: "<<ptr2_a<<endl;
    a=4887;

    cout<<"The value of a is: "<<a<<endl;
    cout<<"The address of a is: "<<ptr_a<<endl;
    *ptr_a=55;
    cout<<"The value of a is: "<<a<<endl;
    cout<<"The address of a is: "<<ptr_a<<endl;

    int A=5;
    int *pointer;
    pointer=&A;
    int **pointer_pointer;
    pointer_pointer=&pointer;
    cout<<"The value of A is:"<<A<<endl;
    cout<<"The value of A is (called by pointer):"<<*pointer<<endl;
    cout<<"The value of A is (called by pointer_pointer):"<<**pointer_pointer<<endl;
    cout<<"The address of A is :"<<pointer<<endl;
    cout<<"The address of A is(called by *pointer_pointer):"<<*pointer_pointer<<endl;
    cout<<"The address of pointer is :"<<pointer_pointer<<endl;
    **pointer_pointer=10;
    cout<<"The value of A after changing the value of **pointer_pointer to 10:"<<A<<endl;

    return 0;

}
