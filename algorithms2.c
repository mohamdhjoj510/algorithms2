#include <stdio.h>
#include <string.h>
#define MAX_STRING 50 /*MAX ENTERED STRING*/
#define MAX_RESULT 100 /*MAX OUTPUT STRING*/
#define CHARACTERS 1 /*THIS IS FOR THE FIRST FUNCTION REQUEST*/
#define CHANGE_BASE 2 /*THIS IS FOR THE SECOND FUNCTION REQUEST*/
#define EXIT 3 /*THIS IS FOR THE THIRD FUNCTION REQUEST*/
#define MAX_FORMAT 3 /*ENTERED FORMAT SIZE*/
#define HEXA 16
#define DECIMAL 10
#define QUATERNARY 4
#define BINARY 2
void different_characters(char* str1, char* str2, char* result);/*FUNCTION STATEMENT*/
void intToNumberBaseString(char *format, int num, char* intToCharArr );

int main()
{
    int request;
    int num;
    int input=0;
    char result[MAX_RESULT];
    char str1[MAX_STRING];
    char str2[MAX_STRING];
    char format[MAX_FORMAT];
    char intToCharArr[MAX_STRING];

    while(1)
    {
        printf("Please select the function you want to run:\n1 - different characters\n2 - print formated integers\n3 - Exit the program\n");
        input=scanf("%d",&request);
        if(input<1)/*CHECK IF THE REQUEST INPUT IS CORRECT (1-3)*/
        {
            printf("Input Error!");
           continue;
        }
        if(request==CHARACTERS)/*REQUEST FOR DIFFRENT_CHARACTER FUNCTION*/
        {
            printf("Enter the first string:\n");/*TAKING STRINGS 1&2 FROM USER*/
            scanf("%s",str1);
            printf("Enter the second string:\n");
            scanf("%s",str2);
            different_characters(str1, str2, result);
            printf("%s\n",result);
            continue;/*ENTER NEW REQUEST AGAIN AFTER FINISHING THE FUNCTION PROCESS*/
        }
        if(request==CHANGE_BASE)/*REQUEST FOR intToNumberBaseString FUNCTION*/
        {
            printf("Enter format and number:\n");/*TAKING FORMAT AND NUMBER FROM USER*/
            scanf("%s %d", format, &num);
            intToNumberBaseString(format, num, intToCharArr);/*SENDING FORMAT,NUMBER,inToCharArr TO THE FUNCTION*/
            if (strcmp(format, "%x") == 0)/*IF USER ENTERED HEXA-DECIMAL FORMAT*/
            {
                printf("%s(%d)\n", intToCharArr, HEXA);
            }
            if (strcmp(format, "%d") == 0)/*IF USER ENTERED DECIMAL FORMAT*/
            {
                printf("%s(%d)\n", intToCharArr, DECIMAL);
            }
            if (strcmp(format, "%4") == 0)/*IF USER ENTERED QUATERNARY FORMAT*/
            {
                printf("%s(%d)\n", intToCharArr,QUATERNARY);
            }
            if (strcmp(format, "%b") == 0)/*IF USER ENTERED BINARY FORMAT*/
            {
                printf("%s(%d)\n", intToCharArr, BINARY);
            }
            continue;
        }
        if(request==EXIT)/*REQUEST FOR ENDING THE PROGRAM*/
        {
            return 0;/*program ended*/
        }
        if(request!=CHARACTERS && request!=CHANGE_BASE && request!=EXIT)/*REQUEST INPUT IS INCORRECT*/
        {
            printf("Input Error!");
            return 1;
        }
    }
}
void different_characters(char* str1, char* str2, char* result)/*FUNCTION DEFINTION*/
{
    int i=0, j=0, k=0, n, m;/*COUNTER VARIABLES*/
    char big_letters[MAX_STRING];
    char numbers[MAX_STRING];
    char small_letters[MAX_STRING];
    int check = 0;/*VARIABLE TO CHECK IF THE CHARACTER IS FOUND OR NOT*/
    char *temp = result;
    char *temp4 = temp;

    while(*(str1+i) != '\0')/*COMPARING FIRST STRING WITH SECOND STRING*/
    {
        j = 0;
        check = 0;
        while(*(str2+j) != '\0')/*CHECK IF THE CHARACTER IS FOUND IN THE SECOND STRING*/
        {
            if(*(str1+i) == *(str2+j))
            {
                check = 1;
                break;
            }
            j++;
        }
        if(check == 0)/*IF THE CHARACTER IS NOT FOUND IN THE SECOND STRING*/
        {
            *(result+k) = *(str1+i);
            k++;
        }
        i++;
    }
    i = 0;
    while(*(str2+i) != '\0')/*COMPARING SECOND STRING WITH FIRST STRING*/
    {
        j = 0;
        check = 0;
        while(*(str1+j) != '\0')/*CHECK IF THE CHARACTER IS NOT FOUND IN THE FIRST STRING*/
        {
            if(*(str2+i) == *(str1+j))
            {
                check = 1;
                break;
            }
            j++;
        }
        if(check == 0)/*IF THE CHARACTER IS NOT FOUND IN THE FIRST STRING*/
        {
            *(result+k) = *(str2+i);
            k++;
        }
        i++;
    }
    *(result+k) = '\0';/*END OF STRING*/
    while (*temp != '\0')/*REMOVING OTHER CHARACTERS*/
    {
        if (!((*temp >= 'a' && *temp <= 'z') || (*temp >= 'A' && *temp <= 'Z') || (*temp >= '0' && *temp <= '9')))
        {
            char* temp2 = temp;
            while(*temp2 != '\0')
            {
                *temp2 = *(temp2 + 1);
                temp2++;
            }
        }
        temp++;
    }
    while(*temp != '\0')
    {
        char* temp2 = temp4 + 1;
        while(*temp2 != '\0')
        {
            if(*temp4 == *temp2)
            {
                char* temp3 = temp2;
                while(*temp3 != '\0')
                {
                    *temp3 = *(temp3 + 1);
                    temp3++;
                }
            }
            temp2++;
        }
        temp4++;
    }
    n = 0;
    for (i = 0; i < strlen(result); i++)/*GETING NUMBERS FROM THE RESULT STRING*/
    {
        if(*(result+i) >= '0' && *(result+i) <= '9')
        {
            *(numbers+n) = *(result+i);
            n++;
        }
    }
    *(numbers+n) = '\0';
    for(i = 0; i < strlen(numbers); i++)/*SORTING NUMBERS UPWARD*/
    {
        for(j = i + 1; j < strlen(numbers); j++)
        {
            if(*(numbers+i) > *(numbers+j))/*SWAP IF THE NUMBER IS SMALLER THAN THE NEXT NUMBER*/
            {
                char temp = *(numbers+i);
                *(numbers+i) = *(numbers+j);
                *(numbers+j) = temp;
            }
        }
    }
    n = 0;
    for(i = 0; i < strlen(result); i++)/*GETING SMALL LETTERS FROM RESULT ARRAY*/
    {
        if (*(result+i) >= 'a' && *(result+i) <= 'z')/*CHECK IF THE CHARACTER IS SMALL LETTER*/
        {
            *(small_letters+n) = *(result+i);
            n++;
        }
    }
    *(small_letters+n) = '\0';
    for (i = 0; i < strlen(small_letters); i++)
    {
        for (j = i + 1; j < strlen(small_letters); j++)/*SORT SMALL LETTERS UPWARD*/
        {
            if (*(small_letters+i) > *(small_letters+j))/*SWAP IF THE SMALL LETTER IS SMALLER THAN THE NEXT SMALL LETTER*/
            {
                char temp = *(small_letters+i);
                *(small_letters+i) = *(small_letters+j);
                *(small_letters+j) = temp;
            }
        }
    }
    n=0;
    for(i = 0; i < strlen(result); i++)
    {
        if(*(result+i) >= 'A' && *(result+i) <= 'Z')/*CHECK IF THE CHARACTER IS BIG LETTER*/
        {
            *(big_letters+n) = *(result+i);
            n++;
        }
    }
    *(big_letters+n) = '\0';
    for(i = 0; i < strlen(big_letters); i++)/*SORT BIG LETTERS UPWARD*/
    {
        for(j = i + 1; j < strlen(big_letters); j++)
        {
            if(*(big_letters+i) > *(big_letters+j))/*SWAP IF THE BIG LETTER IS SMALLER THAN THE NEXT BIG LETTER*/
            {
                char temp = *(big_letters+i);
                *(big_letters+i) = *(big_letters+j);
                *(big_letters+j) = temp;
            }
        }
    }
    m=0;
    for(i = 0; i < strlen(small_letters); i++)/*CONCATENATE THE RESULT--->SMALL LETTERS FIRST*/
    {
        *(result+m) = *(small_letters+i);
        m++;
    }
    for(i = 0; i < strlen(numbers); i++)/*--->NUMBERS*/
    {
        *(result+m) = *(numbers+i);
        m++;
    }
    for(i = 0; i < strlen(big_letters); i++)/*--->BIG LETTERS*/
    {
        *(result+m) = *(big_letters+i);
        m++;
    }
    *(result+m) = '\0';/*END OF RESULT STRING*/
    temp = result;
    while(*temp != '\0')/*REMOVING MATCH CHARS*/
    {
        char* temp2 = temp + 1;
        while(*temp2 != '\0')
        {
            if(*temp == *temp2)
            {
                char* temp3 = temp2;
                while (*temp3 != '\0')
                {
                    *temp3 = *(temp3 + 1);
                    temp3++;
                }
            }
            temp2++;
        }
        temp++;
    }
}
void intToNumberBaseString(char *format, int num, char* intToCharArr )/*SECOND FUNCTION DIFENTION*/
{
    int j, i=0, quotient;
    char temp;
    char hexa_digits[] = "0123456789ABCDEF";/*THIS IS THE HEXA-DECIMAL DIGITS*/
    char decimal_digits[] = "0123456789";/*THIS IS THE DECIMAL DIGITS*/
    char quaternary_digits[] = "0123";/*THIS IS THE QUATERNARY DIGITS*/
    char binary_digits[] = "01";/*THIS IS THE BINARY DIGITS*/

    if (strcmp(format, "%d") == 0)/*FIRST CASE -> DECIMAL*/
    {
        quotient = num;
        if(quotient==0)/*SPECIAL CASE IF THE ENTERED NUMBER IS 0*/
        {
            *(intToCharArr+(i++)) = *(decimal_digits+(quotient % 10));
            quotient = quotient / 10;
        }
        while (quotient != 0) /*CONVERTING DECIMAL NUMBER TO IntToCharArr*/
        {
            *(intToCharArr+(i++)) = *(decimal_digits+(quotient % 10));
            quotient = quotient / 10;
        }
        *(intToCharArr+i) = '\0';
        for (j = 0; j < i / 2; j++) /*REVERSE THE intToCharArr STRING*/
        {
            temp = *(intToCharArr+j);
            *(intToCharArr+j) = *(intToCharArr+(i - j - 1));
            *(intToCharArr+(i - j - 1)) = temp;
        }
    }
    if (strcmp(format, "%x") == 0)/*SECOND CASE -> HEXA-DECIMAL*/
    {
        quotient = num;
        i = 0;
        if(quotient==0)
        {
            *(intToCharArr+(i++)) = *(hexa_digits+(quotient % 16));
            quotient = quotient / 16;
        }
        while (quotient != 0) /*CONVERT THE DECIMAL NUMBER TO CHAR*/
        {
            *(intToCharArr+(i++)) = *(hexa_digits+(quotient % 16));
            quotient = quotient / 16;
        }
        *(intToCharArr+i) = '\0';
        for (j = 0; j < i / 2; j++) /*REVERSING IntToCharArr STRING*/
        {
            temp = *(intToCharArr+j);
            *(intToCharArr+j) = *(intToCharArr+(i - j - 1));
            *(intToCharArr+i - j - 1) = temp;
        }
    }
    if (strcmp(format, "%4") == 0)/*THIRD CASE -> QUATERNARY*/
    {
        quotient = num;
        i = 0;
        if(quotient==0)
        {
            *(intToCharArr+(i++)) = *(quaternary_digits+(quotient % 4));
            quotient = quotient / 4;
        }
        while (quotient != 0) /*CONVERT THE NUMBER TO intToCharArr*/
        {
            *(intToCharArr+(i++)) = *(quaternary_digits+(quotient % 4));
            quotient = quotient / 4;
        }
        *(intToCharArr+i) = '\0';
        for (j = 0; j < i / 2; j++)/*REVERSING IntToCharArr STRING*/
        {
            temp = *(intToCharArr+j);
            *(intToCharArr+j) = *(intToCharArr+(i - j - 1));
            *(intToCharArr+(i - j - 1)) = temp;
        }
    }
    if (strcmp(format, "%b") == 0)/*LAST CASE -> BINARY*/
    {
        quotient = num;
        i = 0;
        if(quotient==0)
        {
            *(intToCharArr+(i++)) = *(binary_digits+(quotient % 2));
            quotient = quotient / 2;
        }
        while (quotient != 0)/*CONCATENATE THE NUMBER TO IntToCharArr*/
        {
            *(intToCharArr+(i++)) = *(binary_digits+(quotient % 2));
            quotient = quotient / 2;
        }
        *(intToCharArr+i) = '\0';
        for (j = 0; j < i / 2; j++)/*REVERSING IntToCharArr STRING*/
        {
            temp = *(intToCharArr+j);
            *(intToCharArr+j) = *(intToCharArr+(i - j - 1));
            *(intToCharArr+(i - j - 1)) = temp;
        }
    }
}




