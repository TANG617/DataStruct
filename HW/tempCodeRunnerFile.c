#include <sys/types.h> 
#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
int var=10;
int main ()
{
pid_t pid;
int num=9;
printf ("before fork\n");
pid=fork();
if (pid<0)
{
perror ("fork");
}
if (pid==0)
{
var++;
num++;
printf (" in son process var=%d, num=%d\n", var, num);
}
else
{
    sleep (1);
    printf ("in father process var=%d, num=%d\n", var, num);

}

printf ("common code area\n");
return 0;
}