//Simple C program to encrypt and decrypt a string

#include <stdio.h>

int main()
{
   int i, x;
   char str[100];
   char again = 'y';
   while (again == 'y')
   {
       printf("\nPlease enter a string: ");
       //gets(str);
       scanf("%s", &str);

       printf("\nPlease choose following options:\n");
       printf("1 = Encrypt the string.\n");
       printf("2 = Decrypt the string.\n");
       scanf("%d", &x);

       //using switch case statements
       switch(x)
       {
       case 1:
          for(i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] + 9 - 2 + 3; //the key for encryption is 3 that is added to ASCII value

          printf("\nEncrypted string: %s\n", str);
          break;

       case 2:
          for(i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] - 9 + 2 - 3; //the key for encryption is 3 that is subtracted to ASCII value

          printf("\nDecrypted string: %s\n", str);
          break;

       default:
          printf("\nError\n");
       }
        printf(" Do you want to use again? (y - n): ");
        again = getc;
   }
   return 0;
}
