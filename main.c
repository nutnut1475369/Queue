#include <stdio.h>
#include <string.h>
#include "Queue.h"

int main(int argc, const char * argv[]) {
    int i,x,n=0,eq=0,dq=0;
    Queue Q;
    Q.head=NULL;
    Q.tail=NULL;
    Q.size=0;
    printf("1.Ramen 120\n2.Sushi 60\n3.Water 5\n");
    for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
          x=dequeue(&Q);
          if(x!=0){
            int cash=0;
            n++;
            printf("Customer no:%d\n",n);
            printf("You have to pay : %d\n",x);
            while (cash<x)
              {
                  printf("Cash : ");
                  scanf("%d",&cash);
              }
            if(cash>x){
              printf("Change : %d\n",cash-x);
            }
                printf("THX\n");
            }
          dq++;
        }
        else {
            enqueue(&Q, atoi(argv[i]),atoi(argv[i+1]));
            printf("My order is %d\n",atoi(argv[i]));
            i++;
            eq++;
        }
    }
    if(eq>dq){
      printf("There are  %d ppl left in queue\n",eq-dq);
    }
    return 0;
}