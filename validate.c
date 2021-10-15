/* Project 1 CPE100
* Created by Doonlayatis (Doon) Kitsakulpaisan
* ID 62070503421
* project due on 24 Oct 2019
* this program will ask user to choose validation to validate input
* then user input string to validate this program contain 4 types of validation
* 1 date and time
* 2 IP address
* 3 Password
* 4 International phone number
* if user choose 5 the program will print the summary and exit
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
/* check for digit in phone number */
int checkphonedigit(char first[],char second[],char third[])
{
    int result,i;       /* boolean result and i for count in loop */
    int one,two,three;  /* variable for each number */
    /* check first number */
    for(i=1;i<strlen(first);i++)
    {
        if(isdigit(first[i]))
        {
            one =0;
        }
        else
        {
            one =1;
            break;
        }
    }
    /* check second number */
    for(i=0;i<strlen(second);i++)
    {
        if(isdigit(second[i]))
        {
            two =0;
        }
        else
        {
            two=1;
            break;
        }
    }
    /* check third number */
    for(i=0;i<strlen(third)-1;i++)
    {
        if(isdigit(third[i]))
        {
            three =0;
        }
        else
        {
            three=1;
            break;
        }
    }
    if(one == 0 && two == 0 && three == 0)
    {
        result = 0;
    }
    else
    {
        result =1;
    }
    return result;
}
/* check for valid dash in phone number */
int checkdash(char str[])
{
    int i=0;                    /* for counting loop */
    int dashcount = 0;          /* counting dash */
    for(i=0;i<strlen(str);i++)
    {
        if(str[i] == '-')
        {
            dashcount++;
        }
    }
    return dashcount;
}
/* validate phone number function */
int validphonenumber(char number[])
{
    int i=0;                                /* for counting loop */
    char *token, *token2, *token3;          /* for taking string from each dash */
    const char dash[2] = "-";               /* constant dash for string token function */
    const char plussign[2] = "+";           /* constant plus for string token function */
    int dashcount,len1,len2,len3,digit;     /* dash counting and length of 3 strings and digit boolean */
    if(number[i] == '+')
    {
        dashcount = checkdash(number);
            if(dashcount == 2)
            {
                token = strtok(number,dash);
                token2 = strtok(NULL,dash);
                token3 = strtok(NULL,dash);
                len1 = strlen(token);
                len2 = strlen(token2);
                len3 = strlen(token3)-1;
                if((len1 >= 2 && len1 <= 4) && (len2 >= 1 && len2 <=3) && (len3 >=6 && len3 <= 10))
                {
                    digit = checkphonedigit(token,token2,token3);
                    if(digit == 0)
                    {
                        printf("    Valid\n");
                    }
                    else
                    {
                        printf("    Not valid - alphabetics\n");
                    }
                }
                else
                {
                printf("    Not valid - wrong format\n");
                }
            }
            else
            {
                printf("    Not valid - illegal dash\n");
            }
    }
    else
    {
        printf("    Not valid - no plus\n");
    }
}
/* function for checking digit in IP address */
int checkIPdigit(char first[],char second[],char third[],char fourth[])
{
    int result,i;                   /* result boolean and counting loop */
    int one,two,three,four;         /* boolean for each validtion */
    for(i=0;i<strlen(first);i++)
    {
        if(isdigit(first[i]))
        {
            one =0;
        }
        else
        {
            one =1;
            break;
        }
    }
    for(i=0;i<strlen(second);i++)
    {
        if(isdigit(second[i]))
        {
            two =0;
        }
        else
        {
            two=1;
            break;
        }
    }
    for(i=0;i<strlen(third);i++)
    {
        if(isdigit(third[i]))
        {
            three =0;
        }
        else
        {
            three=1;
            break;
        }
    }
    for(i=0;i<strlen(fourth)-1;i++)
    {
        if(isdigit(fourth[i]))
        {
            four =0;
        }
        else
        {
            four=1;
            break;
        }
    }
    if(one == 0 && two == 0 && three == 0 && four == 0)
    {
        result = 0;
    }
    else
    {
        result =1;
    }
    return result;
}
/* checking period in IP address */
int checkperiodIP(char IP[])
{
    int i =0;               /* counting loop */
    int periodcount = 0;    /* count period */
    for(i=0;i<strlen(IP);i++)
    {
        if(IP[i] == '.')
        {
            periodcount++;
        }
    }
    return periodcount;
}
/* function for validating IP address */
int validateIPaddress(char IP[])
{
    char *token,*token2,*token3,*token4;    /* get char from string token */
    const char period[2] = ".";             /* constant char to separate the string */
    int checkperiod;                        /* for checking period */
    int len1,len2,len3,len4;                /* for holding length of strings */
    int num1,num2,num3,num4;                /* for holding integer from string */
    int digit;                              /* to receive return value from digit function */
    checkperiod = checkperiodIP(IP);
    if(checkperiod == 3)
    {
        /* separating string */
        token = strtok(IP,period);
        token2 = strtok(NULL,period);
        token3 = strtok(NULL,period);
        token4 = strtok(NULL,period);
        if (token,token2,token3,token4 != NULL)
        {
        /* checking length of string */
        len1 = strlen(token);
        len2 = strlen(token2);
        len3 = strlen(token3);
        len4 = strlen(token4)-1;
        if((len1 >= 1 && len1 <=3) && (len2 >= 1 && len2 <= 3) && (len3 >= 1 && len3 <= 3) && (len4 >= 1 && len4 <= 3))
        {
            digit = checkIPdigit(token,token2,token3,token4);
            if(digit == 0)
            {
                sscanf(token,"%d",&num1);
                sscanf(token2,"%d",&num2);
                sscanf(token3,"%d",&num3);
                sscanf(token4,"%d",&num4);
                if((num1 >= 1 && num1 <= 255) && (num2 >= 0 && num2 <= 255) && (num3 >= 0 && num3 <= 255) && (num4 >= 0 && num4 <= 255))
                {
                    printf("    Valid\n");
                }
                else
                {
                    printf("    Not valid - illegal numbers\n");
                }
            }
            else
            {
                printf("    Not valid - alphabetic characters\n");
            }
        }
        else
        {
            printf("    Not valid - illegal numbers\n");
        }
        }
        else
        {
            printf("    Not valid - illegal numbers\n");
        }
    }
    else
    {
        printf("    Not valid - illegal period\n");
    }
}
/* checking number in password */
int checkpassnumber(char checkpass[])
{
    int i=0;            /* for counting loop */
    int numcount;       /* for counting number */
    int result;         /* for boolean result */
    for(i=0;i<strlen(checkpass);i++)
    {
        numcount = isdigit(checkpass[i]);
        if(numcount >= 2)
        {
            result = 0;
            break;
        }
        else
        {
            result = 1;
        }
    }
    return result;
}
/* function for validating password */
int validatePassword(char password[])
{
    int len,lengthok,upperok,lowerok,digitok,specialok,spaceok,i = 0; /* variable for checking each rules */
    int result = 0;                                     /* boolean result */
    len = strlen(password)-1;                           /* length of string input */
    if(len <= 7 || len >= 13)
    {
        lengthok = 1;
    }
    else
    {
        for(i=0;i<len;i++)
        {
            if(isupper(password[i]))
            {
                upperok=0;
                break;
            }
            else
            {
                upperok=1;
            }
        }
        for(i=0;i<len;i++)
        {
            if(islower(password[i]))
            {
                lowerok=0;
                break;
            }
            else
            {
                lowerok=1;
            }
        }
        for(i=0;i<len;i++)
        {
            if(password[i] == '?' || password[i] == '@' || password[i] == '%' || password[i] == '$' || password[i] == '#')
            {
                specialok=0;
                break;
            }
            else
            {
                specialok=1;
            }
        }
        for(i=0;i<len;i++)
        {
            if(checkpassnumber(password))
            {
                digitok =0;
                break;
            }
            else
            {
                digitok=1;
            }
        }
        for(i=0;i<len;i++)
        {
            if(password[i] != ' ')
            {
                spaceok =0;
            }
            else
            {
                spaceok=1;
                break;
            }
        }
    }
    if(lengthok==1 || lowerok==1 || upperok==1 || digitok==1 || specialok==1 || spaceok==1)
    {
        printf("    Not valid - password does not follows rules\n");
    }
    else
    {
        printf("    Valid\n");
    }
}
/* checking time */
int checktime(int hh,int tt)
{
int result; /* return value */
    if(hh >= 0 && hh <= 23)
    {
        if(tt >= 0 && tt <= 59)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}
/* checking day */
int checkday(int dd, int mm, int yyyy)
{
int result; /* return value */
    if((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
    {
        result = 1;
    }
    else if((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
    {
        result = 1;
    }
    else if((mm == 2) && (yyyy %4==0) && (dd>=1 && dd<=29))
    {
        result = 1;
    }
        else if((mm == 2) && (yyyy %4!=0) && (dd>=1 && dd<=28))
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}
/* date and time validating function */
int validateDateTime(char checkDateTime[])
{
    int i = 0;                      /* counting loop */
    int result,status,time = 0;     /* boolean value */
    int yyyy,mm,dd,hh,tt;           /* date and time variable */
    int len = strlen(checkDateTime)-1; /*length of date and time */

    if(len<=16 && len>=12)
    {
        sscanf(checkDateTime,"%d-%d-%d %d:%d",&yyyy,&mm,&dd,&hh,&tt);
                if(yyyy >= 1919 && yyyy <= 2119)
                {
                    if(mm >= 1 && mm <= 12)
                    {
                        status = checkday(dd,mm,yyyy);
                        if(status == 1)
                        {
                            time = checktime(hh,tt);
                            if(time == 1)
                            {
                                printf("    Valid\n");
                            }
                            else
                            {
                                printf("    Not valid - illegal time\n");
                            }
                        }
                        else
                        {
                            printf("    Not valid - illegal day\n");
                        }
                    }
                    else
                    {
                        printf("    Not valid - illegal month\n");
                    }
                }
                else
                {
                    printf("    Not valid - year outside range\n");
                }
    }
    else
    {
        printf("    Not valid - wrong format\n");
    }
}
/* control function to call validation function */
int controldatetime(int choice,int count[])
{
    char input[128]; /* for user input */
    while (choice == 1) /* user selected choice 1 */
    {
        printf("Validation date and time yyyy-mm-dd hh:tt (Hit return to stop)\n");
        memset(input,0,sizeof(input));
        printf("   Enter date and time : ");
        fgets(input,sizeof(input),stdin);
        if(strlen(input) == 1)
        {
            break;
        }
        else
        {
            count[0]++;
            validateDateTime(input);
        }
    }
}
int controlIPaddress(int choice, int count[])
{
    char input[128];
    while (choice == 2 ) /* user selected choice 2 */
    {
        printf("Validation IP address (Hit return to stop)\n");
        memset(input,0,sizeof(input));
        printf("   Enter IP address : ");
        fgets(input,sizeof(input),stdin);
        if(strlen(input) == 1)
        {
            break;
        }
        else
        {
            count[1]++;
            validateIPaddress(input);
        }
    }
}
int controlPassword(int choice,int count[])
{
    char input[128];
    while (choice == 3) /* user selected choice 3 */
    {
        printf("Validation password against a set of rules (Hit return to stop)\n");
        memset(input,0,sizeof(input));
        printf("   Enter password : ");
        fgets(input,sizeof(input),stdin);
        if(strlen(input) == 1)
        {
            break;
        }
        else
        {
            count[2]++;
            validatePassword(input);
        }
    }
}
int controlphone(int choice,int count[])
{
    char input[128];
    while (choice == 4) /* user selected choice 4 */
    {
        printf("Validation international phone number (Hit return to stop)\n");
        memset(input,0,sizeof(input));
        printf("   Enter phone number : ");
        fgets(input,sizeof(input),stdin);
        if(strlen(input) == 1)
        {
            break;
        }
        else
        {
            count[3]++;
            validphonenumber(input);
        }
    }
}
int controlfunction(int choice, int count[])
{
    if(choice == 1)
    {
       controldatetime(choice,count);
    }
    else if(choice == 2)
    {
        controlIPaddress(choice,count);
    }
    else if(choice == 3)
    {
        controlPassword(choice,count);
    }
    else if(choice == 4)
    {
        controlphone(choice,count);
    }
}
/* function for printing menu and summary */
int main()
{
    char stringinput[32];       /* for user input */
    int validchoices = 0;       /* holding choice */
    int count[4] = {0,0,0,0};   /* array for count summary */
    while (validchoices != 5)
    {
        printf("Validation options: ");
        printf("\n   1 - Check date and time in form yyyy-mm-dd hh:tt");
        printf("\n   2 - Check IP Address");
        printf("\n   3 - Check password against a set of rule");
        printf("\n   4 - Check international phone number");
        printf("\n   5 - Exit the program\n");
        printf("What do you want to do? ");
        fgets(stringinput,sizeof(stringinput),stdin);
        sscanf(stringinput,"%d",&validchoices);
        if ((validchoices >= 1) && (validchoices <= 4))
        {
            controlfunction(validchoices,count);
        }
        else if (validchoices == 5)
        {
            break;
        }
    }
    /* print summary */
    if (validchoices == 5)
    {
        printf("\nProgram run summary:\n");
        printf("    Validation type 1: %d\n",count[0]);
        printf("    Validation type 2: %d\n",count[1]);
        printf("    Validation type 3: %d\n",count[2]);
        printf("    Validation type 4: %d\n\n",count[3]);
        printf("Goodbye!");
        exit(0);
    }
}
