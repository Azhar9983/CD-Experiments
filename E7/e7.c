//Compiler design program to find the FOLLOW of given grammer.
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int n,m=0,p,i=0,j=0;
char a[10][10],follow_result[10];
void follow(char c);
void first(char c);
void add_results(char);
int main()
{
 int i;
 int choice;
 char c,ch;
 clrscr();
 printf("Enter the no.of productions: ");
scanf("%d", &n);
 printf(" Enter %d productions\nProduction with multiple terms should be give as separate productions \n", n);
 for(i=0;i<n;i++)
  scanf("%s%c",a[i],&ch);
    do
 {
  m=0;
  printf("Find FOLLOW of -->");
  scanf(" %c",&c);
  follow(c);
  printf("FOLLOW(%c) = { ",c);
  for(i=0;i<m;i++)
   printf("%c ",follow_result[i]);
  printf(" }\n");
  printf("Do you want to continue(Press 1 to continue....)?");
 scanf("%d",&choice);
 }
 while(choice==1);
}
void follow(char c)
{
    if(a[0][0]==c)add_results('$');
 for(i=0;i<n;i++)
 {
  for(j=2;j<strlen(a[i]);j++)
  {
   if(a[i][j]==c)
   {
    if(a[i][j+1]!='\0')first(a[i][j+1]);
    if(a[i][j+1]=='\0'&&c!=a[i][0])
     follow(a[i][0]);
   }
  }
 }
}
void first(char c)
{
      int k;
                 if(!(isupper(c)))
      /*f[m++]=c;  */
                     add_results(c);
                 for(k=0;k<n;k++)
                 {
                 if(a[k][0]==c)
                 {
                 if(a[k][2]=='#') follow(a[i][0]);
                 else if(islower(a[k][2]))
      /*f[m++]=a[k][2];    */
                     add_results(a[k][2]);
                 else first(a[k][2]);
                 }
                 }
}
void  add_results(char c)
{
    int i;
    for( i=0;i<=m;i++)
        if(follow_result[i]==c)
            return;
   follow_result[m++]=c;
} 