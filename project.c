//Hospital management system

#include<stdio.h>
struct details
{
    int id;
    char name[50];
    int age;
    char disease[50];
};
struct doctor
{
    int id;
    char name[50];
    char dept[100];
};
struct Appoint
{
    int id;
    int patientid;
    int doctorid;
    char date[20];
};
struct medicine
{
    int id;
    char name;
    int quantity;
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
    scanf("%d",&id);
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
void delete(struct details d[])
{
    int id,found=0;
    printf("Enter Patient id:");
    scanf("%d",&id);
    for(int i=0; i<count; i++)
    {
        if(d[i].id == id)
        {
            found = 1;
            for(int j; j<count-1; j++)
            {
            d[j]= d[j+1];
            }
        count--;
        printf("Patient deleted");
        break;
        }
    }
    if(!found)
    {
        printf("Patient not found");
    }
}
int dcount=0;
void adddoc(struct doctor doc[])
{
    printf("\n--------Add Doctor-------\n");
    printf("Enter doctor id:");
    scanf("%d",&doc[dcount].id);
    printf("Enter doctor name:");
    scanf("%s",doc[dcount].name);
    printf("Enter department:");
    scanf("%s",doc[dcount].dept);
    dcount++;
    printf("Doctor added successfully\n");
}
void view(struct doctor doc[])
{
    printf("\n------Doctor list--------\n");
    if(dcount==0)
    {
        printf("No doctor found\n");
        return;
    }
    else
    {
        for(int i=0; i<dcount; i++)
        {
            printf("\nDoctor %d\n",i+1);
            printf("ID:%d\n",doc[i].id);
            printf("Name:%s\n",doc[i].name);
            printf("Department:%s\n",doc[i].dept);
        }
    }
}
int acount=0;
void appoint(struct Appoint a[])
{
    printf("\n----------Add appointment---------\n");
    printf("Enter appointment  id:");
    scanf("%d",&a[acount].id);
    printf("Enter patient id:");
    scanf("%d",&a[acount].patientid);
    printf("Enter doctor id:");
    scanf("%d",&a[acount].doctorid);
    printf("Enter date:");
    scanf("%s",a[acount].date);
    acount++;
    printf("Appointment added succesfully\n");
}
void viewappoint(struct Appoint a[])
{
    printf("\n---------Appointment list-----------\n");
    if(acount==0)
    {
        printf("No appointment");
        return;
    }
    for(int i=0; i<acount;i++)
    {
        printf("\nAppointment %d\n",i+1);
        printf("ID:%d\n",a[i].id);
        printf("Patient id:%d\n",a[i].patientid);
        printf("Doctor id:%d\n",a[i].doctorid);
        printf("Date:%s\n",a[i].date);
    }
}
void cancel(struct Appoint a[])
{
    int id,found=0;
    printf("\nEnter appointment id:");
    scanf("%d",&id);
    for(int i=0;i<acount;i++)
    {
        if(a[i].id==id)
        {
            found=1;
            for(int j=1;j<acount-1;j++)
            {
                a[j]=a[j+1];
            }
            acount--;
            printf("Appointment cancelled\n");
            break;
        }
    }
    if(!found)
    {
        printf("Appointment not found\n");
    }
}
int mcount=0;
void addmed(struct medicine m[])
{
    printf("\n----------Add Medicine-----------\n");
    printf("Enter medicine id:");
    scanf("%d",&m[mcount].id);
    printf("Enter Medicine name:");
    scanf(" %s",&m[mcount].name);
    printf("Enter quantity:");
    scanf("%d",&m[mcount].quantity);
    mcount++;
    printf("Medicine added succesfully");
}
void viewmed(struct medicine m[])
{
    printf("\n--------Medicine stock---------\n");
    if(mcount==0)
    {
        printf("No medicine found\n");
        return;
    }
    for(int i=0;i<mcount;i++)
    {
        printf("Medicine id:%d\n",m[i].id);
        printf("Name:%c\n",m[i].name);
        printf("Quantity:%d\n",m[i].quantity);
    }
}
void update(struct medicine m[])
{
    int id,q,found=0;
    printf("\nEnter medicine id:");
    scanf("%d",&id);
    for(int i=0;i<mcount;i++)
    {
        if(m[i].id==id)
        {
            found=1;
            printf("Enter quantity:");
            scanf("%d",&q);
            if(q>m[i].quantity)
            {
                printf("Not enough stock\n");
                return;
            }
            m[i].quantity-=q;
            printf("Stock updated succesfully\n");
            break;
        }
    }
    if(!found)
    {
        printf("Medicine not found\n");
    }
}
int main()
{
    struct details d[100];
    struct doctor doc[100];
    struct Appoint a[100];
    struct medicine m[100];
    int choice;
    printf("-------------Hospital Management System------------\n");
    while(1)
    {
        printf("\n---------Main menu---------\n");
        printf("1.Add patient\n");
        printf("2.View patient\n");
        printf("3.Search patient\n");
        printf("4.Delete patient\n");
        printf("5.Add doctor\n");
        printf("6.View doctor\n");
        printf("7.Add appointment\n");
        printf("8.View appointment\n");
        printf("9.Cancel appointment\n");
        printf("10.Add medicine\n");
        printf("11.View medicine\n");
        printf("12.Update medicine stock\n");
        printf("13.Exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: add(d); break;
            case 2: display(d); break;
            case 3: search(d); break;
            case 4: delete(d); break;
            case 5: adddoc(doc); break;
            case 6: view(doc); break;
            case 7: appoint(a); break;
            case 8: viewappoint(a); break;
            case 9: cancel(a); break;
            case 10: addmed(m); break;
            case 11: viewmed(m); break;
            case 12: update(m); break;
            case 13: printf("Exiting\n"); return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

