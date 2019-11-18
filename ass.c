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
    // Variables
    char isbn[100];

    //exit 0
    while (1) {
      /* code */


    //code
    printf("%s\n", "Please enter your ISBN");
    scanf("%s", isbn );

    //Check digit & hyphen
    for (int i = 0; i < 100; i++) {
      if (isdigit(isbn[i])  || (isbn[i] == "-")) {

        //seperate into 5 elements/
        int i = 0;
        char *tok = NULL;
        tok = strtok(isbn, "-");
        int a = atoi (tok);  //1st element into integer
        if ((a == 978) || (a == 979)) {

          int tok2 = strtok (isbn, "-");
          int b = atoi(tok2);  //2nd elemnet into integer
          if (/* condition */) {
            /* code */
          } else {
            printf("%s\n","2nd elemenet must be 1-5 digits" );
          }
        } else {
          printf("%s\n", "Prefix element must 978 or 979 " );
        }
      } else {
        printf("%s\n","Input must be digits and hyphens" );
      }


  }
    }
    return 0;
  }
