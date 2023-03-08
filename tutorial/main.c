# include<stdio.h>
# include<curses.h>
main()
{
int i ;
initscr() ;                              /* turn on curses*/
clear();
for ( i=0; i < LINES; i++) {
        move(i,i+i);
                if (i%2 == 1)
                standout();
        addstr("Hello,World");
        if ( i%2 == 1) 
                standend();
        sleep(1);
        refresh();
        }
endwin();         /* reset the tty etc */
}