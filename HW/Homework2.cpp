#include<iostream>
#include<string>
#define MAXN 1001
using namespace std;
int main()
{
    char currentCharacter;
    char opSeq[MAXN];
    int currentPosition=0;
    while(scanf("%c",&currentCharacter)!=EOF)
    {
        if(currentCharacter=='[' || currentCharacter == '(' || currentCharacter == '{')
        {
            opSeq[currentPosition]=currentCharacter;
            currentPosition++;
        }
        else if(currentCharacter==']')
        {
            if (opSeq[currentPosition-1]=='[') currentPosition--;
            else {
                printf("Error");
                return 0;
            }
        }
        else if(currentCharacter==')')
        {
            if (opSeq[currentPosition-1]=='(') currentPosition--;
            else {
                printf("Error");
                return 0;
            }
        }
        else if(currentCharacter=='}')
        {
            if (opSeq[currentPosition-1]=='{') currentPosition--;
            else {
                printf("Error");
                return 0;
            }
        }
        
    }
}