#include <iostream>
#include <vector>
using namespace std;
vector <int> maxsubsum(vector<int>a) //�o��function�p��maxsubsum�ðO��̥���̥k��element��index(�f�t��Ƶ��cCH2 P.25)
{
    int maxsubsum=0;
    int current_sum=0;
    int left_element=0;
    int right_element=0;
    vector <int> result;
    for (int i=0; i<a.size(); i++)
    {
        current_sum+=a[i];
        if (current_sum>maxsubsum)
        {
            maxsubsum=current_sum;
            right_element=i;
        }
        if (current_sum<0){
            current_sum=0;
            left_element=i+1;
        }
    }
    result.push_back(maxsubsum);
    result.push_back(left_element);
    result.push_back(right_element);
    return result; //�^�Ǫ��Ovector �N�i�H�@�����ܦh��T
}


int main()
{
    vector <int>a;
    vector <int>b;
    int a_pushback; //�H��varioable�ӰO��cin��value
    cout<<"Please input a number to pushback into vector a:";
    cin>>a_pushback;
    while(cin.good()) //�Hcin.good()�h�ˬdinput�쩳�O���Ointeger �n�O���O�N���n�A���ϥΪ�input
    {
        a.push_back(a_pushback); //��input���vector a
        cout<<"Please input a number to pushback into vector a(or press any button which is not number to step to maxsubsum):";
        cin>>a_pushback;

    }
    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i]<<" ";

    }
    b=maxsubsum(a);
    cout<<endl;
    cout<<"the maxsubsum of a is:"<<b[0]<<endl;
    cout<<"the maxsubsum consists of elements mentioned below"<<endl;
    for(int i=b[1]; i<=b[2]; i++)
    {
        cout<<a[i]<<" ";
    }
}
