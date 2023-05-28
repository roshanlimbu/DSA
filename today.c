// wap to append data into a data file without opening it in apppend mode
#include <stdio.h>
#include <conio.h>
void updates(){
  FILE *fp1, *fp2;
  int id;
  char name[100];
  fp1= fopen("emp.dat","r");
  fp2= fopen("temp.dat","w");
  while (feof(fp1)==0) {
    fscanf(fp1,"%d%s",&id, name ); 
    fscanf(fp2,"%d%s", id, name);
  }
  fclose(fp1);
  fclose(fp2);

}
int main(){
  updates();
}
