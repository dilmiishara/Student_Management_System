// developed by Wimalaweera R.B.D.I. (2021t01258)
// Student Information Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct studentcourse
{
    char scid[50];
    char cgrade[5];
};

struct student
{
    char index[20];
    char name[50];
    char department[50];
    int no_of_courses;
    struct studentcourse std[30];
};

struct course
{
    char cid[50];
    char cname[100];
    int creditvalue;
};


// print patterns
void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}


//main menu
char menu()
{
  system("cls");
  system("COLOR 03");
  printf("\n\n\t");
  printChar('=',37);
  printf(" WELCOME TO STUDENT MANAGEMENT SYSTEM ");
  printChar('=',37);
  printf("\n\n\n\t");

  printChar('*',112);

  printf("\n\n\n\n\t\t\t\t\t1. Add Student");
  printf("\n\n\t\t\t\t\t2. Add Course");
  printf("\n\n\t\t\t\t\t3. Show All Students & GPA");
  printf("\n\n\t\t\t\t\t4. Search Student");
  printf("\n\n\t\t\t\t\t5. Modify Student");
  printf("\n\n\t\t\t\t\t6. Remove Student");
  printf("\n\n\t\t\t\t\t7. Show all Courses ");
  printf("\n\n\t\t\t\t\t8. Exit ");
  printf("\n\n\n\n\t");

  printChar('*',112);

  printf("\n\n\n\t\t\t\t\tEnter Your Option :--> ");
  char option;
  scanf("%c",&option);
  while(option!='1' && option!='2' && option!='3' && option!='4' && option!='5' && option!='6' && option!='7' && option!='8' )
  {
      printf("\n\n\t\t\t\t\t\aInvalid Enter......!!\n\t\t\t\t\tPlease Enter (1/2/3/4/5/6/7/8) to continue :--> ");
      scanf("%c",&option);
      fgetc(stdin);
  }

  switch(option)
  {
      case'1':
          addstudent(); // to add student details
          break;

      case'2':
          addcourse(); // to add course details
          break;

      case'3':
          showstudentsd(); // to show student details
          break;

      case'4':
          Indivisualview(); // to search student details
          break;

      case'5':
          modify(); // to update student details
          break;

      case'6':
          removes(); // to remove student
          break;

      case'7':
          showcourse(); // to show course details
          break;

      case'8':
          printf("\n\t\t......Thank you for using this system....");
          break; // exit

      default:
          printf("thank u");
  }
}


// add student details
void addstudentdetails()
{

    struct student s;
    FILE *student;
    student=fopen("studentdetails.txt","a");

        printf("\n\n\n\t\tEnter Index number of Student: ");
        scanf(" %[^\n]s",s.index);

        printf("\n\n\t\tEnter Full Name of student: ");
        scanf(" %[^\n]s",s.name);

        printf("\n\n\t\tEnter Department: ");
        scanf(" %[^\n]s",s.department);

        printf("\n\n\t\tEnter number of Courses : ");
        int count;
        scanf("%d",&count);
        s.no_of_courses=count;

        for (int a=0;a<count;a++)
        {
            printf("\n\n\t\t\t%d. Enter Course ID : ",a+1);
            scanf(" %[^\n]s",s.std[a].scid);

            printf("\n\t\t\t   Enter Course Grade (A/B/C/D/E/AB-Absent) : ",a+1);
            scanf(" %[^\n]s",s.std[a].cgrade);

        }


    fgetc(stdin);
    fwrite(&s,sizeof(struct student),1,student);
    fclose(student);

    if(fwrite!=0)
    {
        printf("\n\n\n\t\t");
        printChar('-',95);
        printf("\n\n\t\tDetails are written to the file");
        printf("\n\n\t\tPress Enter key to exit :--> ");
        fgetc(stdin);
    }

menu();

}


// print title and patterns
void addstudent()
{
    system("cls");
    printf("\n\n\t\t");
    printChar('=',37);
    printf(" ADD STUDENT DETAILS ");
    printChar('=',37);
    printf("\n");

    addstudentdetails();
}


// add course details
void addcoursedetails()
{
  char another;

  struct course c;
  FILE *cur;

// get course details from the user
  printf("\n\n\n\t\tEnter Course ID : ");
  scanf(" %[^\n]s",c.cid);

  printf("\n\n\t\tEnter Course Name : ");
  scanf(" %[^\n]s",c.cname);

  printf("\n\n\t\tEnter Credit Value : ");
  scanf(" %d",&c.creditvalue);

      cur=fopen("coursedetails.txt","a"); // open file
      fwrite(&c,sizeof(struct course),1,cur); // write details in file
      fclose(cur); // close file

      if(fwrite!=0) // check the details are written or not
      {
          printf("\n\n\n\t\t");
          printf("\n\n\t\tDetails are written to the file");

      }

      printf("\n\n\t\t");
      printChar('*',95);
      printf("\n\t");

      printf("\n\n\t\tPress Enter key to Exit :--> ");
      scanf("%c",&another);
      fgetc(stdin);
      menu();

}


// print title and patterns
void addcourse()
{
    system("cls");
    printf("\n\n\t\t");
    printChar('=',37);
    printf(" ADD COURSE DETAILS ");
    printChar('=',37);
    printf("\n");

    addcoursedetails();
}


// display student details and GPA value
void showstudentdetails()
{

  FILE *Studentdetails;
  FILE *Coursedetails;

  struct student s;
  struct course c;

  int m=0; // variable is used to the print numbers

  Studentdetails=fopen("studentdetails.txt","r");

  if(Studentdetails==NULL) // check the student file is empty or not
  {
      printf("\n\n\t\tCan't open Student_details file !!!");
      char d;
      printf("\n\t\tBefore use student details Enter student details to the file");
      printf("\n\t\tPress Enter key to add students :--> ");
      scanf("%c",&d);
      fgetc(stdin);
      addstudent();
  }

  printf("\n\n\n\tNO\tIndex no\t\tFull name\t\t\t\t\t\t\t    ");
  printf("Department\t     Course ID\t  Course grade\n");
  printf("\n\t");
  printChar('-',150);
  printf("\n\n\t");

      while(fread(&s,sizeof(struct student),1,Studentdetails)){

              int tot_credit=0;
              float tot_GPA=0.0, cre_gra=0.0;

              m=m+1;

              printf("\n\t");
              printf("%d",m);
              printf("\t");

              printf("%-20s%-75s%-15s",s.index,s.name,s.department);

              Coursedetails=fopen("coursedetails.txt","r");

              if(Coursedetails==NULL) // check the course file is empty or not
              {
                  printf("\n\n\t\tCan't open Course details file !!!");
                  char d;
                  printf("\n\t\tBefore use course details Enter course details to the file");
                  printf("\n\t\tPress Enter key to add course :--> ");
                  scanf("%c",&d);
                  fgetc(stdin);
                  addcourse();
              }

              for(int a=0; a<s.no_of_courses; a++){

                  while(fread(&c,sizeof(struct course),1,Coursedetails)){

                      for(int k=0; k<s.no_of_courses ;k++){

                          if(strcmp(s.std[k].scid,c.cid)==0){
                              tot_credit+=c.creditvalue;

                              if(strcmp("A",s.std[a].cgrade)==0)
                                  cre_gra+=c.creditvalue*4.0;

                              else if(strcmp("B",s.std[a].cgrade)==0)
                                  cre_gra+=c.creditvalue*3.0;

                              else if(strcmp("C",s.std[a].cgrade)==0)
                                  cre_gra+=c.creditvalue*2.5;

                              else if(strcmp("D",s.std[a].cgrade)==0)
                                  cre_gra+=c.creditvalue*1.5;

                              else if(strcmp("E",s.std[a].cgrade)==0)
                                  cre_gra+=c.creditvalue*0.0;

                              else if(strcmp("AB",s.std[a].cgrade)==0)
                                  cre_gra+=c.creditvalue*0.0;
                          }
                      }
                      break;
                  }
                  printf("%-15s%-15s\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       ",s.std[a].scid,s.std[a].cgrade);

              }
              fclose(Coursedetails);
              tot_GPA=cre_gra/tot_credit; // calculate the final GPA value
              printf("\n\n\t\t\t\tCurrent GPA : %.2f",tot_GPA);

              printf("\n\t");
              printChar('-',150);
              printf("\n\n\t");

      }
      fclose(Studentdetails);
      printf("\n\n\n\t\t");
      printChar('*',120);
      printf("\n\t");

      char d;
      printf("\n\n\t\tPress Enter key to Exit :--> ");
      scanf("%c",&d);
      fgetc(stdin);
      menu();

}


// print title and patterns
void showstudentsd()
{
    system("cls");
    printf("\n\n\t\t");
    printChar('=',50);
    printf(" All STUDENT DETAILS ");
    printChar('=',50);
    printf("\n");

    showstudentdetails();

}


// search one student details
void showonestudentdetails()
{
  char id[20];
  char an;
  int flag;
  struct student s;
  char another;

  FILE *showstudent;
  showstudent=fopen("studentdetails.txt","r");

  printf("\n\n\n\t\tEnter Index Number : ");
  scanf("%s",&id);

  while(fread(&s,sizeof(struct student),1,showstudent))
  {
    if(strcmp(id,s.index)==0) // check the index numbers are equal
    {
      flag=1;

      printf("\n\n\t\tIndex       : %s",s.index);
      printf("\n\n\t\tName        : %s",s.name);
      printf("\n\n\t\tDepartment  : %s",s.department);
      printf("\n\n\t\tCourses  ");

      int c;
      c=s.no_of_courses;
      for(int a=0; a<c; a++)
      {
          printf("\n\n\t\t\t%d. Course id : %s",a+1,s.std[a].scid);
          printf("\n\t\t\t   Grade     : %s",s.std[a].cgrade);
      }

    }
  }

    if(flag==0)
    {
      printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");
    }

    fclose(showstudent);

    printf("\n\n\n\t\t");
    printChar('-',94);

    printf("\n\n\t\tShow another student information? (Y/N)?");
    printf("\n\t\tEnter Your Option :--> ");

    scanf("%s",&an);
    fgetc(stdin);

    another= an;

    if(another =='y' || another =='Y')
    {
      showonestudentdetails(); // repeat
    }

    else
    {
      menu(); // back to menu
    }

}


// display the title and patterns
void Indivisualview()
{
    system("cls");
    printf("\n\n\t\t");
    printChar('=',37);
    printf(" STUDENT DETAILS ");
    printChar('=',37);
    printf("\n");

    showonestudentdetails();
}


// update student details
void modifystudent()
{
    struct student s1,s2;
    char tempid[20];

    FILE *showstudent;
    FILE *copy;

    showstudent=fopen("studentdetails.txt","r+"); // open student details file
    copy =fopen("copy.txt","w"); // open extra file to copy details

    printf("\n\n\t\tEnter Index Number of Student to MODIFY the Record : ");
    scanf("%s",&tempid);
    fgetc(stdin);

    if(showstudent==NULL)
    {
      fprintf(stderr,"\n\n\t\t Can't open the file");
      exit(1);
    }

    while(fread(&s1,sizeof(struct student),1,showstudent))
    {
        if(strcmp(tempid,s1.index)!=0)
        {
            fwrite(&s1,sizeof(struct student),1,copy); // copy the details
        }
        else
        {
             // new details for to update the record
              printf("\n\n\t\t\tEnter New Data for the student");

              printf("\n\n\n\t\tEnter Index number of Student : ");
              scanf(" %[^\n]s",s2.index);

              printf("\n\n\t\tEnter Full Name of student : ");
              scanf(" %[^\n]s",s2.name);

              printf("\n\n\t\tEnter Department : ");
              scanf(" %[^\n]s",s2.department);

              printf("\n\n\t\tEnter number of Courses : ");
              int count;
              scanf("%d",&count);
              s2.no_of_courses=count;

              for (int a=0;a<count;a++)
              {
                  printf("\n\n\t\t\t%d. Enter Course ID : ",a+1);
                  scanf(" %[^\n]s",s2.std[a].scid);

                  printf("\n\t\t\t   Enter Course Grade (A/B/C/D/E/AB-Absent) : ",a+1);
                  scanf(" %[^\n]s",s2.std[a].cgrade);

              }

              fwrite(&s2,sizeof(struct student),1,copy); // write the new details

        }
    }

    fclose(showstudent);
    fclose(copy);

    remove("studentdetails.txt"); // remove  student details file
    rename("copy.txt","studentdetails.txt"); // rename copy file

    printf("\n\n\t\tRecord Updated successfully ");

    char another;
    printf("\n\n\t\tPress Enter key to Exit :--> ");
    scanf("%c",&another);
    fgetc(stdin);
    menu();

}


// display title and patterns
modify()
{
  system("cls");
  printf("\n\n\t\t");
  printChar('=',37);
  printf(" MODIFY STUDENT DETAILS ");
  printChar('=',37);
  printf("\n");

  modifystudent();
}


// show all course details
void showcoursedetails()
{
  FILE *showcourse;
  showcourse=fopen("coursedetails.txt","r");

  struct course c;

  printf("\n\n");
  if(showcourse==NULL)
  {
     printf("\n\n\t\tCan't open Course details file !!!");
    char d;
    printf("\n\t\tBefore view course details Enter course details to the file");
    printf("\n\t\tPress Enter key to add students :--> ");
    scanf("%c",&d);
    fgetc(stdin);
    addcourse(); // to add course details
  }

  else
  {

  int a=0;

  printf("\n\n\n\t\tNO\tCourse ID\tCourse Name\t\t\tCredit Value\n\n");

  while(fread(&c,sizeof(struct course),1,showcourse))
  {
      a=a+1;

      printf("\n\t\t");
      printf("%d",a);
      printf("\t");

      printf("%-15s%-40s%-20d",c.cid,c.cname,c.creditvalue);
   }

 }

    printf("\n\n\n\n\t\t");
    printChar('*',90);
    printf("\n\t");

    char another;
    printf("\n\n\t\tPress Enter key to Exit :--> ");
    scanf("%c",&another);
    fgetc(stdin);
    menu();


}


// display the title and patterns
void showcourse()
{
    system("cls");
    printf("\n\n\t\t");
    printChar('=',37);
    printf(" COURSE DETAILS ");
    printChar('=',37);
    printf("\n");

    showcoursedetails();

}


// remove student
void removestudent()
{
    struct student s1;
    char tempid[20];

    FILE *showstudent;
    FILE *copy;

    showstudent=fopen("studentdetails.txt","r+"); // open student details file
    copy =fopen("copy.txt","a+"); // open extra file

    printf("\n\n\t\tEnter Index Number of Student to Remove : ");
    scanf("%s",&tempid);
    fgetc(stdin);

    if(showstudent==NULL)
    {
      fprintf(stderr,"\n\n\t\t Can't open the file");
      exit(1);
    }

    while(fread(&s1,sizeof(struct student),1,showstudent))
    {
        if(strcmp(tempid,s1.index)!=0)
        {
            fwrite(&s1,sizeof(struct student),1,copy); // copy the details of students except input index
        }
    }

    fclose(showstudent);
    fclose(copy);

    remove("studentdetails.txt"); // remove student details file
    rename("copy.txt","studentdetails.txt");// rename the extra file

    printf("\n\n\t\tRemoved Updated successfully ");

    char another;
    printf("\n\n\t\tPress Enter key to Exit :--> ");
    scanf("%c",&another);
    fgetc(stdin);
    menu();

}


// display title and patterns
removes()
{
  system("cls");
  printf("\n\n\t\t");
  printChar('=',37);
  printf(" MODIFY STUDENT DETAILS ");
  printChar('=',37);
  printf("\n");

  removestudent();
}


int main()
{
    menu();

    return 0;
}
