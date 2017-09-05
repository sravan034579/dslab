#include<stdio.h>
#include<stdlib.h>
 struct poly
 {
   int exp,coef;

  };
int main()
{
  struct poly *apoly,*bpoly,*result;
  int n1,n2,pa=0,pb=0,pc=0,i;
  printf("enter the size of the firt poly :\n ");
  scanf("%d",&n1);
  apoly=(struct poly*)malloc(sizeof(struct poly)*(n1*2));
  printf("enter the elements \n");
  for(i=0;i<n1;i++)
  {
     scanf("%d %d",&apoly[i].coef,&apoly[i].exp);
  }
   printf("enter the size of the second poly : \n");
   scanf("%d",&n2);
   bpoly=(struct poly*)malloc(sizeof(struct poly)*(n2*2));
   printf("enter the elements of second poly : \n");
  for(i=0;i<n2;i++)
    {
       scanf("%d %d",&bpoly[i].coef,&bpoly[i].exp);
    }
   result=(struct poly*)malloc(sizeof(struct poly)*((n1+n2)*2));
   while(pa<n1 && pb <n2)
   {
	 if(apoly[pa].exp==bpoly[pb].exp)
	  {
	       result[pc].exp=apoly[pa].exp;
		   result[pc].coef=apoly[pa].coef+bpoly[pb].coef;
		   pa++,pb++,pc++;
	  }
	 else if(apoly[pa].exp<bpoly[pb].exp)
	   {
		 result[pc].exp=bpoly[pb].exp;
		 result[pc].coef=bpoly[pb].coef;
		 pc++,pb++;
	   }
	 else
	   {
		 result[pc].exp=apoly[pa].exp;
		 result[pc].coef=apoly[pa].coef;
		 pc++,pa++;
	   }
    }
 while(pa<n1)
    {
	  result[pc].exp=apoly[pa].exp;
	  result[pc].coef=apoly[pa].coef;
	  pc++,pa++;
    }
 while(pb<n2)
   {
	 result[pc].exp=bpoly[pb].exp;
	 result[pc].coef=bpoly[pb].coef;
	 pc++,pb++;
    }
  printf("the polynomial addition is :");
  for(i=0;i<((n1>n2)?n1:n2);i++)
    {
	  printf("%d X %d \n",result[i].coef,result[i].exp);
    }
}

