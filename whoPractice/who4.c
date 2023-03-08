/* who4.c - who with buffered reads
*  Identity crisis: The manual page for who lists who   am   i 
as an acceptable *usage of     *   the command. 
It also lists whoami. Modify who2.c so it supports the who am i *usage. 
*   Experiment with the command whom and read the manage. 
How does it differ from who    
*   am i ? write a program that works like whoami.
*/

#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main()
{
    struct utmp uNameRecord;
    int utmpFD;
    int reclen = sizeof(struct utmp);

    char *loginName;
    loginName = getlogin();

    utmpFD = open(UTMP_FILE, O_RDONLY);

    if (utmpFD == -1)
    {
        perror(UTMP_FILE);
        _exit(1);
    }

    // reading file contents of the specified amount of bytes
    while(read(utmpFD, &uNameRecord, reclen) == reclen)
    {
        printf("%s\n", loginName);
        break;
    }
        

    close(utmpFD);
    return 0;
}