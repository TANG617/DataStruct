#include <sys/types.h> 
#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
int main ()
{
int fd1;
int fd2 = 3;
int err = 0;
int dd;
err = dup2(1, fd2);
if (err<0)
{
perror("dup2");
}
printf ("fd2=%d, err=%d\n", fd2, err);
fd1 = open ("test", O_CREAT|O_RDWR, S_IRWXU) ; 
dup2(fd1, 1);

printf ("hello world\n");
dd=dup2 (fd2, 1);
printf ("dd=%d \n", dd);
printf ("I love linux In");
return 0;
}