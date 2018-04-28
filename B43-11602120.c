#include<stdio.h>
#include<semaphore.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
//n=no. of Contestants  b=
sem_t s;
void game();
void detail();
void game()
{
        sem_wait(&s);
        printf("Game is running..\n");
        sleep(5);
        printf("Game is finished\n");
        sem_post(&s);
}
void detail()
{
        printf("\t\t\t***********************WELCOME TO ONLINE MULTIPLAYER GAME**************************\n");
        printf("\t\t\t\t\tThis Online Multiplayer game is designed by:");
        printf("\n\t\t\t\t\t\tName-Ankit Pawar\n\t\t\t\t\t\tSection-K1651\n\t\t\t\t\t\tRoll No.-B43\n\t\t\t\t\t\tReg No-11602120\n");
}


int main()
{
    detail();
    sem_init(&s,0,1);
    int n,i,k;
    printf("Enter the Number of Contestants who want play:-\n");
    scanf("%d",&n);
        if(n<3)
        {
            printf("There must be minimum 3 Contestants for starting the game\n");

        }
if(n%3!=0)
	{ 
       		int c=n/3;
       		printf("The game can be played %d times with these number of Contestants\n",c);
        	if(c>=1)
		{
			int i;
        	for(i=0;i<c;i++)		
			{						
        		game();
			}
		}
		int b=n%3;
		int z;
		abc:
        printf("To run the game for 1 more time %d more Contestants are required ",3-b);
        scanf("%d",&z);
        if(3-b==z)
		{
        	game();
		}
		else
			{
				if(3-b>z)
					{
						b=b+z;
						goto abc;
					}
				else
					{
						printf("\nExcess Contestants\n");
						exit(0);
					}
			}
    }
else
	{
        n=n/3;
       	printf("The game can be played %d times with these number of Contestants\n",n);
       	for(i=0;i<n;i++)
      		{
				game();
			}
	}
}

