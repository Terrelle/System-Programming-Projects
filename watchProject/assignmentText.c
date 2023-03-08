#include <stdio.h>
#include <utmp.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define TOTAL_USERS 10

char *listOfLoggedInUsers[TOTAL_USERS];
int numOfloggedInUsers = 0;

void addUser(char *username);
void removeUser(char *username);
bool isUserloggedIn(char *username);



int main(int argc, char *argv[])
{
    int i, interval = 300;
    struct utmp *entry;


    if (argc < 2) {
        printf("Insufficient arguments \n", argv[0]);
        return 1;
    }

    // assumes the first integer entered to be the interval time
    if (isdigit(*argv[1])) {
        interval = atoi(argv[1]);

        // skip the first argument and point to the next 
        // one and reduce count
        argv++;
        argc--;
    }



    while (1) {
        printf("Checking...\n");
        setutent();

        while ((entry = getutent())) {

            if (entry->ut_type == USER_PROCESS) {

                for (i = 1; i < argc; i++) {
                    /*
                    comparing the username in the current entry 
                    of the utmp file with the username in the command line argument list.
                    */
                    if (strcmp(entry->ut_user, argv[i]) == 0) {
                      // if logged in user wasn't in array  
                        if (!isUserloggedIn(argv[i])) {
                            printf("%s logged on\n", argv[i]);
                            // add the user to our array
                            addUser(argv[i]);
                        }
                    }
                }
            }
                
        }

        endutent();
       

        for (i = 1; i < argc; i++) {
            if (!isUserloggedIn(argv[i])) {
                printf("%s logged off\n", argv[i]);
                removeUser(argv[i]);
            }
        }
        
        sleep(interval);
    }

return 0;
}

void addUser(char *username)
{
    // creating a duplicate of username in memory and adding to array
    listOfLoggedInUsers[numOfloggedInUsers++] = strdup(username);
}

void removeUser(char *username)
{
    
    for (int i = 0; i < numOfloggedInUsers; i++) {
        /*
        If the username exists, it removes it from the list by 
        shifting the elements of the array to fill the empty
        space created
        */
        if (strcmp(listOfLoggedInUsers[i], username) == 0) {
        listOfLoggedInUsers[i] = listOfLoggedInUsers[--numOfloggedInUsers];
        break;
        }
    }
}

bool isUserloggedIn(char *username)
{
        // Keeping track of number of users logged on
    for (int i = 0; i < numOfloggedInUsers; i++) {
        if (strcmp(listOfLoggedInUsers[i], username) == 0) {
        return true;
        }
    }
 return false;
}