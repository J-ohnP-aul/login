#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
// #include<window.h>
struct  user
{
    /* data */
    char fullNmae[50];
    char email[50];
    char password[50];
    char username[50];
    char phoneNo[50];
};


void takeInput(char ch[50]){
    fgets(ch,50,stdin);
    //ch[strlen(ch) - 1] accesses the last character of the string.
    ch[strlen(ch) - 1] = 0;
}

char generateUsername(char email[50],char username[50]){
    //noblemen@gmail.com
    for(int i = 0; i<strlen(email);i++){
        if(email[i] == '@') break;
        else username[i] = email[i];
    }
    // return username
}

void takepassword(char pwd[50]){
    int i;
    char ch;
    while (1)
    {
        ch = getchar();
        if(ch ==  ENTER || ch == TAB){
            pwd[i] = '\0';
            break;
        }else if(ch == BCKSPC){
            if(i>0){
                i--;
                printf("\b \b");//abc
            }
        }else{
            pwd[i++] = ch;
            printf("* \b");
        }
    }
    
}

int main()
{
    system("clear");
    FILE *fp;
    int opt,userFound;
    userFound = 0;
    struct user user;
    char password2[50];
    
    printf("\n\t\t\t-----------Welcome to the login system---------");
    printf("\n\t1.Sign up");
    printf("\n\t2.Login");
    printf("\n\t3.exit");

    printf("\n\t choose your value :\t");
    scanf("%d",&opt);
    fgetc(stdin);

    switch ((opt))
    {
    case 1:
        system("clear");
        printf("\nEnter your full name:\t");
        takeInput(user.fullNmae);
        printf("Enter your email:\t");
        takeInput(user.email);
        printf("Enter your phone number\t");
        takeInput(user.phoneNo);
        printf("Enter your password\t");
        takeInput(user.password);
        printf("\nconfirm your password:\t");
        takeInput(password2);

        if(!strcmp(user.password,password2)){
            // printf("\nYour password matched");
            generateUsername(user.email,user.username);
            // printf("\nyour user name is: %s",user.username);
            fp = fopen("users.txt", "a+");//open afile if not exist create a new and cusor at end for appending
            fwrite(&user,sizeof(struct user),1,fp);//store to db
            if(fwrite != 0) printf("\nUser registration succes, your user-name is %s",user.username);
            else printf("SORRY SOMETHING WENT WRONG!!");
        }else{
            printf("\npassword did not match");
            // putchar('\a'); sound woyi
            // system("echo -e '\a'");
        }
        printf("\n\n---------------------------\n");
        fclose(fp);
        break;

    case 2:
        char username[50],pword[50];
        struct user usr;

        printf("\nEnter your user name:\t");
        takeInput(username);
        printf("\nEnter your password:\t");
        takeInput(pword);

        fp = fopen("users.txt","r");
        while(fread(&usr,sizeof(struct user),1,fp)){//defined struct sizeofit, n
            if(!strcmp(usr.username,username)){
                if(!strcmp(usr.password,pword)){
                    system("clear");
                    printf("\n\t\t\t\tWelcome back %s",usr.fullNmae);
                    printf("\n\n|Full name:\t%s",usr.fullNmae);
                    printf("\n\n|Email    :\t%s",usr.email);
                    printf("\n\n|username:\t%s",usr.username);
                    printf("\n\n|contact:\t%s",usr.phoneNo);
                }else{
                    printf("\n\nINVALID PASSWORD");
                }
                userFound = 1;
            }
        }
        if(!userFound){
            printf("\n\nUser is not registered");
        }
        fclose(fp);
        break;
    case 3:
        printf("\n\t\t\tBye Bye fella :)");
        return 0;
    default:
        break;
    }


    return 0;
}