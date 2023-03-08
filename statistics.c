#include<stdio.h>
#include<stdlib.h>

void compute_stats(struct numlist *listptr);
void output(struct numlist *ptr);

struct numlist 
    {
        float *list;
        int len;
        float min;
        float max;
        float avg;
    };

int main(int argc, char *argv[])
{
    struct numlist *ptrNumList; // pointer to numlist struture
    ptrNumList = (struct numlist* )malloc(sizeof(struct numlist)); //allocate memory for the strcuture
    
    if(NULL == ptrNumList) // if memory allocation fails
    {
        printf("Failed to allocate memory");
        return -1; 
    }

    // length of elements in the list

    int numOfelements; 
    printf("Enter length of elements: ");
    scanf("%d",&numOfelements);

    ptrNumList->list = (float *)malloc(sizeof(float)*numOfelements); //alllocate memory for the list
    
    if(NULL == ptrNumList->list) //if memory allocation fails
    {
        printf("Failed to allocate memory");
        
        return -1; 
    }

    ptrNumList->len = numOfelements; //intialize the len member of the strcuture

    for(int i = 0; i < ptrNumList->len; i++) // traverse the empty list
    {
        printf("Element %d: ", i+1);
        scanf("%f",&(ptrNumList->list)[i]); //store elements entered by the user in the list
    }

        compute_stats(ptrNumList); // initialize the elements
        output(ptrNumList); // display the min, max, avg

    }



   
void compute_stats(struct numlist *listptr) 
    {

        if(listptr->len > 0) 
        { 
            // setting default values 0 to min, max, and sum so that we can use them
            // to traverse later
            float min = (listptr->list)[0];
            float max = (listptr->list)[0];
            float total = (listptr->list)[0];


            // time to update actual values in the list and designate them as either max or min
            for(int i = 1; i < listptr->len; i++)
            {
                // logic to get greatest value in the list
                if((listptr->list)[i] > max)
                    max = listptr->list[i];
                if((listptr->list)[i] < min)
                    min = listptr->list[i];
                
                // grabbing total to strike average of each value
                total = total + listptr->list[i];
            }

                // updating the structure

                listptr->max = max;
                listptr->min = min;
                listptr->avg = total/(listptr->len);
        }

    }

    /* Output */
void output(struct numlist *ptr) 
{

    for(int i = 0; i < ptr->len; i++) //traverse the list
    {
        printf("%.3f ",(ptr->list)[i]); 
        printf("\n");
    }
    printf("\nLength : %d", ptr->len);
    printf("\nBiggest Element : %.3f", ptr->max); //will print only 3 digits after decimal point
    printf("\nSmallest Element : %.3f", ptr->min);
    printf("\nAverage of all elements is: %.3f\n", ptr->avg);
    }
