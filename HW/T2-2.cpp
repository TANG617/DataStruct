#include<iostream>
using namespace std;
int list[1001];
void OutPut()
{
    int maxdepth=0;
    for (int i = 'A'; i < 'Z'; i++)
    {
        if(list[i]>maxdepth)
        {
            maxdepth=list[i];
        }
    }
    cout<<maxdepth<<endl;
    
}
int main()
{
    while(1)
    {
        char L,R;
        cin>>L>>R;
        if(L=='#')
        {
            if(R=='#')
            {
                OutPut();
                return 0;
            }
            list[R]=1;
        }
        else
        {
            list[R]=list[L]+1;
        }
        
    }
}