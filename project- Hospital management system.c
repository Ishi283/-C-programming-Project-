//Hospital management system

#include<stdio.h>
struct details
{
    int id;
    char name[50];
    int age;
    char disease[50];
};
int count =0;
void add( struct details d[])
{
    printf("\n--------Add Patient--------\n");
    printf("Enter Patient id:");
    scanf("%d",&d[count].id);
    printf("Enter the patient name:");
    scanf("%s",d[count].name);
    printf("Enter the age:");
    scanf("%d",&d[count].age);
    printf("Enter the disease:");
    scanf("%s",d[count].disease);
    count++;
    printf("Patient added succesfully\n");
}
void display(struct details d[])
{
    printf("\n------Patient list--------\n");
    if(count==0)
    {
        printf("No patients found\n");
        return;
    }
    else
    {
        for(int i=0; i<count; i++)
        {
            printf("\nPatient %d\n",i+1);
            printf("ID:%d\n",d[i].id);
            printf("Name:%s\n",d[i].name);
            printf("Age:%d\n",d[i].age);
            printf("Disease:%s\n",d[i].disease);
        }
    }
}
void search(struct details d[])
{
    int id,found=0;
    printf("\nEnter patient id to search:");
    sacnf("%d",&id);
    for(int i=0; i<count; i++)
    {
        if(d[i].id == id)
        {
            printf("\n------Patient found--------");
            printf("\nPatient %d\n",i+1);
            printf("ID:%d\n",d[i].id);
            printf("Name:%s\n",d[i].name);
            printf("Age:%d\n",d[i].age);
            printf("Disease:%s\n",d[i].disease);
            found=1;
            break;
        }
    }
    if(!found)
    {
        printf("Patient not found");
    }
}

