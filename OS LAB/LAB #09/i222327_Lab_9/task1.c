#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<time.h>

typedef struct 
{
int ID;
int score;
char result[5];
}Student;


void* grade_exam(void* arg)
{
    Student* student = (Student*)arg;
    
    
    student->score = rand() % 51 + 50;  
    
   if (student->score >= 60)
    {
        strcpy(student->result, "Pass");
    } 
    else
    {
        strcpy(student->result, "Fail");
    }

    pthread_exit(NULL);
}


void main()
{

int num_students;
scanf("%d",&num_students);

 Student students[num_students];
 pthread_t threads[num_students];

for (int i = 0; i < num_students; i++) 
{
        students[i].ID = i + 1;
        
}


    for (int i = 0; i < num_students; i++)
    {
        pthread_create(&threads[i], NULL, grade_exam, &students[i]);

    }

for (int i = 0; i < num_students; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nExam Results:\n");
    printf("ID\tScore\tResult\n");
    printf("----------------------\n");
    for (int i = 0; i < num_students; i++) 
    {
        printf("%d\t%d\t%s\n", students[i].ID, students[i].score, students[i].result);
    }

    printf("\nAll exam papers have been graded!\n");

    
}





    

  


