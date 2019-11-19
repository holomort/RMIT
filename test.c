/*
  RMIT University Vietnam
  Course: EEET2448 Comp Eng/EEET2601 Eng Comp 1
  Semester: 2019C
  Author: Cao Hoang Long
  ID: 3822921
  Created Date: 17/11/2019
  last modified: 19/11/2019
  Ackknowledgement: If you use any resources, acknewledge here. Failure to do so will be considered plagiarism.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  int duck;
  while (duck=1) {

  //Variables
  char inp[100],inpnum[100];
  char inpone[20],inptwo[20],inpthree[20],inpfour[20],inpfive[20];
  int i=0;
  int hypn =0, num =0;
  int len,lentwo,lenthree,lenfour,lenfive,inputlen;
  int eleone,eletwo,elethree,elefour,elefive;


  printf("%s\n","Please input ISBN code" );
  scanf("%s",inp );
  len = strlen(inp);
  //inputlen = strlen(inp);
  //long exit= atoi(inp);
  //printf("%ld\n",exit );
  if ( len == 1 && *inp == '0' ) {
      printf("Thank you for using this program :D\n" );
      break;
  }

  //string to digits, count numbers and hyphens
  for (int j = 0; j < len; j++) {
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
        if (num>13) {                           // digit count
          printf("%s\n","Invalid ISBN, More than 13 digits" );
        } else {
          if (num<13) {                    //digit count
            printf("%s\n","Invalid ISBN, Less than 13 digits" );
          } else {                            // split into 5 elements
            sscanf(inp, "%d-%d-%d-%d-%d", &eleone,&eletwo,&elethree,&elefour,&elefive );
            //printf("%d,%d,%d,%d,%d",eleone,eletwo,elethree,elefour,elefive );
            if ((eleone != 978) &&(eleone != 979)) { //checks first ele
              printf("%s\n", "Invalid ISBN, First prefix must be 978 or 979");
            } else {
              sprintf(inptwo,"%d",eletwo);
              lentwo= strlen(inptwo);
              if (lentwo > 5) {                        //checks second ele
                printf("%s\n","Invalid ISBN, Second element must be 5 or less digits" );
              } else {
                sprintf(inpthree,"%d",elethree);
                lenthree= strlen(inpthree);
                if (lenthree > 7) {                       //checks third ele
                  printf("%s\n","Invalid ISBN, Third element must be 7 or less digits" );
                } else {
                  sprintf(inpfour,"%d",elefour);
                  lenfour= strlen(inpfour);
                  if (lenfour > 6) {                            //checks fourth ele
                    printf("%s\n","Invalid ISBN, Fourth element must be 6 or less digits" );
                  } else {
                    sprintf(inpfive,"%d",elefive);
                    lenfive= strlen(inpfive);
                    if (lenfive > 1) {                        //checks fifth ele
                      printf("%s\n","Invalid ISBN, Fifth element must be 1 digit" );
                      } else {
                        //VALIDATION test
                        //printf("%s\n",inpnum );
                        int order,totalval;
                        int inpnumbers;
                        sscanf(inpnum, "%d", &inpnumbers);

                        for (i = 1; i < 14; i++) {
                            order = inpnumbers % 10;
                            inpnumbers = inpnumbers / 10;
                            if (i%2==1) {
                                totalval =+ order;
                            } else {
                                totalval =+ order*3;
                            }
                                if (totalval%10 == 0) {
                                printf("%s\n","Failed Validation Test, Invalid ISBN" );
                                break;
                                } else {
                                printf("%s\n","Valid ISBN" );
                                break;
                            }
                        }

                    }
                  }
                }
              }
            }
          }
        }
      }
    }

//978-123456-1-23-4   element2 test isbn
//978-1-12345678-1-1    CANT TEST ELEMENT 3 BUT IT SHOULD WORK
//978-1-1-1234567-1   element 4  test
//978-1234-123-1-41   element 5 test
//978-0-13-376131-3 VALID FINAL TEST
//978-0-13-376131-2 INVALID FINAL Test
}
  return 0;
}
