/*
  RMIT University Vietnam
  Course: EEET2448 Comp Eng/EEET2601 Eng Comp 1
  Semester: 2019C
  Author: Cao Hoang Long
  ID: 3822921
  Created Date: 17/11/2019
  last modified:
  Ackknowledgement: If you use any resources, acknewledge here. Failur to do so will be considered plagiarism.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {

  //Variables
  char inp[20],inpnum[20];
  int i=0;
  int hypn =0, num =0;
  int len;

  //begin
  printf("%s\n","Please input ISBN code" );
  scanf("%s",inp );
  len = strlen(inp);

  //string to digits, count numbers and hyphens
  for (int j = 0; j < 20; j++) {
    if (isdigit(inp[j])) {
      num ++;
      inpnum[i]=inp[j];
      i++;
    } else if (inp[j] == '-'){
       hypn ++;
    }
    }
    if (hypn+num != len) {                       //Char check
      printf("%s\n","Invalid ISBN, must be only digits and hyphens" );
    } else {
      if ((inpnum[i] == '-')&&(inpnum[i++] == 'i')) {        //element check
        printf("%s\n","Invalid ISBN, ISBN only has 5 elements separated by hyphens" );
      } else {
        if (len>17) {                           // digit count
          printf("%s\n","Invalid ISBN, More than 13 digits" );
        } else {
          if (len<17) {                    //digit count
            printf("%s\n","Invalid ISBN, Less than 13 digits" );
          } else {

          }
        }
      }
    }

    printf("%s\n","valid?");
  return 0;
}
