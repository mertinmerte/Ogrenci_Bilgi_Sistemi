#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

 int bubble(int*,int);
 void filewrite();
 void avgmarks();
 void fileprint();
 void filesort();
 void rollin();


int bubble(int x[],int n)
{
 int hold,j,pass,i,switched = 1;
 for(pass = 0; pass < n-1 && switched == 1;pass++)
 {
  switched=0;
  for (j=0;j<n-pass-1;j++)
   if (x[j]>x[j+1])
   {
    switched=1;
    hold = x[j];
    x[j] = x[j+1];
    x[j+1]=hold;
    }
   }
return(0);
}


void filewrite()
{
  int roll,ch,mark;
  char nam[50];
   FILE *fp;
   system("cls");
  fp = fopen("student.txt","a");
   printf("Numara,Isim ve Puan giriniz.(Her bilgiden sonra Enter'a basiniz.') \n");
  ch =1;
  while(ch)
  {
  scanf("%d%s%d",&roll,&nam,&mark);
  fprintf(fp,"%d %s %d\n",roll,nam,mark);
  printf("\n\n0_Durmak icin basiniz.\n1_Devam etmek icin basiniz.");
  scanf("%d",&ch);
  }
   fclose(fp) ;
}

void fileprint()
{
  int marks[100],rollno[100],x[100],i;
  char name[100][50];
  FILE *fp;

  system("cls");
  fp = fopen("student.txt","r");
   i=0;
   printf("Numara     Isim        Puan\n");
   while(!feof(fp))
  {
     fscanf(fp,"%d %s %d\n",&rollno[i],&name[i],&marks[i]);
     printf(" %d          %s          %d\n",rollno[i],name[i],marks[i]);
     i=i+1;
   }
   fclose(fp);
   printf("\n\n\nHerhangi bir tusa basiniz");
   getch();

  }
/******************* SORTING FILE ************************/
void filesort()
  { int marks[100],rollno[100],x[100],n,i,j;
    char name[100][50];
    FILE *fp,*fm;

    fp = fopen("student.txt","r");
    fm = fopen("marks.txt","w");
    i=0;
   while(! feof(fp))
    {

     fscanf(fp,"%d %s %d\n",&rollno[i],&name[i],&marks[i]);
     x[i]= marks[i];
     i=i+1;
      }

       n=i;

       bubble(x,n);

    for(i=0;i<n;i++)
    {
    printf(" %d\t",x[i]);
    }

 for(i=0;i<n;i++)
 {
   for (j=0;j<n;j++)
   {
   if(x[i]==marks[j])
   {
      fprintf(fm,"%d %s %d\n",rollno[j],name[j],marks[j]);
     }
   }
 }
  fclose(fm);
  fclose(fp);
  printf("\n\n\nHerhangi bir tusa basiniz");
  getch();

}
/************************* DATA USING ROLLNO***************************/
void rollin()
{   int i,roll,ch,mark,roll1;
    char nam[50];
    FILE *fm;

    ch=1;
  while(ch)
  { system("cls");
    fm = fopen("marks.txt","r");
    printf(" \nNumara Giriniz. - ");
    scanf("%d",&roll1);
      i=0;
   while(! feof(fm))
    {
     fscanf(fm,"%d %s %d\n",&roll,&nam,&mark);
     if(roll1==roll)
    {printf("\nNumara     Isim        Puan\n ");
     printf(" %d          %s          %d\n",roll,nam,mark);
     break;
     }
     else
     i=i+1;
      }
  printf("\n\n 0_Ana menuye donmek icin basiniz., 1_Ogrenci bilgisini goruntulemek icin\n");
  scanf("%d",&ch);
  fclose(fm);
  }



 }

void avgmarks()
 {
    int marks[100],rollno[100],n,i;
    float avg,x;
    char name[100][50];
    FILE *fm;
    fm = fopen("marks.txt","r");
    i=0;
   while(! feof(fm))
    {

     fscanf(fm,"%d %s %d\n",&rollno[i],&name[i],&marks[i]);
     x = x + marks[i];
     i=i+1;
      }
     n = i;
   avg = x/n;
  printf("%d Ogrencinin ortalamasi -  %f ",n,avg);
  fclose(fm);
  printf("\n\n\nHerhangi bir tusa basiniz");
   getch();

 }


/**************** FUNC. ENDS************************/
int main()
{
  int marks[100],rollno[100],x[100],n,i,j,roll,c,mark,roll1;
  char name[100][10],nam[50];

  while(c!=6)
   {  
     system("cls");
     printf("--Secim Yapiniz--\n\n");
     printf("1_Ogrenci Bilgilerini Girmek icin tiklayiniz.\n\n");
     printf("2_Ogrenci tablosunu goruntulemek icin tiklayliniz.\n\n");
     printf("3_Puanlari siralamak icin tiklayliniz.\n\n");
     printf("4_Numarasini girdiginiz ogrencinin bilgileri icin tiklayliniz.\n\n");
     printf("5_Notlarin ortalamasini goruntulemek icin tiklayliniz.\n\n");
     printf("6_Cikmak icin tiklayliniz.\n\n--");
     scanf("%d",&c);
     system("cls");
     switch(c)
     {
     case 1:
          filewrite();
          break;
     case 2:
          fileprint();
         break;
     case 3:
         filesort();
         break;
     case 4:  rollin();
          break;
     case 5:  avgmarks();
          break;
     case 6:
          break;
     default:
          break;
     }
    }

  }
