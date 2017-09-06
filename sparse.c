#include<stdio.h>
#include<stdlib.h>
struct smarray
{
	
	int r,c,v;
};
void main()
{
	
	int pc=1,pa=1,pb=1,nb,i,nt;;
	struct smarray *ar,*br,*ra; 
	printf("enter the non zero elements in an array :");
	scanf("%d",&nt);

	ar = (struct smarray *) malloc(sizeof(struct smarray) * nt);
    br = (struct smarray *) malloc(sizeof(struct smarray) * nb);
    ra =(struct smarray *) malloc(sizeof(struct smarray)*(nt+nb));
	printf("enter the elements of the first array :\n ");
	for(i = 1; i <= nt; i++)
	{
	     scanf("%d%d%d",&ar[i].r,&ar[i].c,&ar[i].v); 
	}
    printf("enter the  non zero elements of the second matrix :\n");
    scanf("%d",&nb);
	printf("the elements of second sparse matrix is : \n");
	for(i = 1; i <= nb; i++)
	{
		scanf("%d %d %d",&br[i].r,&br[i].c,&br[i].v);
	}
	printf("the elements of the first sparse martix :\n");
	/*for(i=0;i<nt;i++)
	{

		printf("%d %d %d\n", ar[i].r,ar[i].c,ar[i].v);
	}
	printf("the elements of the second sparse martix :\n ");
	for(i=0;i<nb;i++)
	{
		printf("%d %d %d \n ",br[i].r,br[i].c,br[i].v);
	}*/
	while(pa<=nt && pb<=nb)
	{
	 if(ar[pc].r==br[pb].r)
	  {
         if(ar[pa].c==br[pb].c)
           {
             ra[pc].r=ar[pa].r;
             ra[pc].c=ar[pa].c;
             ra[pc].v=ar[pa].v + br[pb].v;
             pa++;
             pb++;
             pc++;
            }
          else if(ar[pa].c < br[pb].c)
            {
              ra[pc].r=ar[pa].r;
              ra[pc].c=ar[pa].c;
              ra[pc].v=ar[pa].v;
              pa++;
              pc++;

            }
          else //(ar[pa].c > br[pb].c)
            {
              ra[pc].r=br[pb].r;
              ra[pc].c=br[pb].c;
              ra[pc].v=br[pb].v;
              pc++;
              pb++;

            }

    	} 
    	else if(ar[pa].r < br[pb].r)
           {
            
              ra[pc].r=ar[pa].r;
              ra[pc].c=ar[pa].c;
              ra[pc].v=ar[pa].v;
              pa++;
              pc++;

           }
           else  //(ar[pa].r>br[pb].r)
             {

              ra[pc].r=br[pb].r;
              ra[pc].c=br[pb].c;
              ra[pc].v=br[pb].v;
              pc++;
              pb++;
             }

    }
    while (pa<=nt)
    {
    	      ra[pc].r=ar[pa].r;
              ra[pc].c=ar[pa].c;
              ra[pc].v=ar[pa].v;
              pa++;
              pc++;

    }
    while (pb<=nb)
    {

              ra[pc].r=br[pb].r;
              ra[pc].c=br[pb].c;
              ra[pc].v=br[pb].v;
              pc++;
              pb++;

    }

    printf("after addition the resultant matrix is :");
     for(i = 1; i < pc; i++)
     {
     	printf("\n%d %d %d", ra[i].r, ra[i].c, ra[i].v);
     }
} 