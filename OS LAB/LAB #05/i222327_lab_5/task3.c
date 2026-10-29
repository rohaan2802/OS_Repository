#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


void main()
{
int arr1[2],arr2[2],arr3[2],num,fact=1,sum=0,cube,buffer[3];
printf("\n ENTER A NUMBER :       ");
scanf("%d",&num);
printf("\n\n");
pipe(arr1);
pipe(arr2);
pipe(arr3);


int process_id_1=fork();

if(process_id_1>0) //FIRST_PARENT
{
close(arr1[1]);
read(arr1[0],&buffer[2],sizeof(buffer[2]));
printf("\n\nFIRST PARENT RECEIVED FACTORIAL :  %d \n\n",buffer[2]);
close(arr1[0]);

int process_id_2=fork();

if(process_id_2>0)//SECOND_PARENT
{

close(arr2[1]);
read(arr2[0],&buffer[1],sizeof(buffer[1]));
printf("\n\nSECOND PARENT RECEIVED SUM :  %d \n\n",buffer[1]);
close(arr2[0]);

int process_id_3=fork();

if(process_id_3>0)//THIRD_PARENT
{
close(arr3[1]);
read(arr3[0],&buffer[0],sizeof(buffer[0]));
printf("\n\nTHIRD PARENT RECEIVED CUBE :  %d \n\n",buffer[0]);

close(arr3[0]);
}

else//THIRD_CHILD
{
close(arr3[0]);
cube=num*num*num;
write(arr3[1],&cube,sizeof(cube));

close(arr3[1]);
}

}
else //SECOND_CHILD
{
close(arr2[0]);
for(int i=1;i<=num;i++)
{
	sum=sum+i;
}
write(arr2[1],&sum,sizeof(sum));

close(arr2[1]);
}

}

else //FIRST_CHILD
{
close(arr1[0]);
for(int i=1;i<=num;i++)
{
	fact=fact*i;
}
write(arr1[1],&fact,sizeof(fact));

close(arr1[1]);
}








}
