#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


struct student
{
    char fullName[50];
    char email[50];
    char regNo[50];
    char password[50];
    char userName[50];
};
void loginsite();
int inptDta(void);
char takeInput(char ch[50]);
char generateUserName(char email[50],char username[50]);
void displaylogin();
int main()
{
    loginsite();
    return 0;
}
void loginsite()
{
    system("clear");
    int opt;
    FILE *fpa,*fpr;
    struct student user;

    do
    {   
        displaylogin();
        opt = inptDta();
        /* code */
        switch(opt){
            case 1:{
                char password2[50];
                system("clear");
                printf("\n\t\t>>>>>LOGIN DETAILS <<<<<\n\n");
                printf("\t\tEnter your full name:        ");
                takeInput(user.fullName);
                printf("\n\t\tEnter your email adress:   ");
                takeInput(user.email);
                printf ("\n\t\tEnter your RegNo:         ");
                takeInput(user.regNo);
                printf("\n\t\tEnter your password:       ");
                takeInput(user.password);
                system("clear");
                printf("\n\t\tRe-enter your password for confimation: ");
                takeInput(password2);
                // system("clear");

                if(!strcmp(user.password, password2)){//strcmp returns 0-false if the str are equal
                    generateUserName(user.email,user.userName);
                    printf("\n\t\tpassword matched, welcome:\t%s\n\n",user.userName);
                    
                    fpa = fopen("database.dat", "a");
                    printf("\n\t\t###>>You are sucsessfully loged in to the system");
                    fwrite(&user,sizeof(struct student),1,fpa);
                    if(fwrite != 0) printf("\n\n\t\tUser registration succes, your user-name is %s\n",user.userName);
                    else printf("SORRY SOMETHING WENT WRONG!!");
                    // if(fpa == NULL){
                    //     printf("\n\t\tError ocured in eading database");
                    // }
                    // else{
                    // }
                }else{
                    printf("\n\n\t\t><><><!!!password did not match!!");
                }
                fclose(fpa);
                break;
            }case 2:{
                int userFound = 0;
                system("clear");
                char usernamecmp[50],passwordcmp[50];
                struct student std1;
                printf("\n\t\tEnter your user name:\t");
                takeInput(usernamecmp);
                printf("\n\t\tEnter your password :\t");
                takeInput(passwordcmp);

                fpr = fopen("database.dat","r");

                while(fread(&std1,sizeof(struct student),1,fpr)){
                    if(!strcmp(std1.userName,usernamecmp)){
                        if(!strcmp(std1.password,passwordcmp)){
                            system("clear");
                            printf("\n\t\t\t\tWelcome back %s",std1.userName);
                            printf("\n\t|Full name:\t%s",std1.fullName);
                            printf("\n\t|Email    :\t%s",std1.email);
                            printf("\n\t|username :\t%s",std1.userName);
                            printf("\n\t|Reg numb :\t%s",std1.regNo);
                            printf("\n\t|_________________|\n\n\n");

                        }else{
                            printf("\n\t\tINVALID PASSWORD!!");
                        }
                        userFound = 1;
                    }
                }
                if(!userFound){
                    printf("\n\t\tUSER NOT REGISTERD KINDLY REGISTER!!");
                }
                fclose(fpr);
                break;
            }case 3:{
                system("clear");
                printf("\n\t _________________");
                printf("\n\t| BYE BYE FELLA :}|");
                printf("\n\t|_________________|");
                break;// return 0;
            }default:
                system("clear");
                printf("\n\n\t\tINVALID INPUT !!");

        }
    } while (opt != 3);   

}
void displaylogin(){
    printf("\n\t\t===========>>WELCOME TO THE SCHOOL LIBRARY system<<<============\n");
    printf("\t\t\t1.Sign up\n");
    printf("\t\t\t2.Login\n");
    printf("\t\t\t3.Exit .");
}
char takeInput(char ch[50]){
    fgets(ch,50,stdin);
    ch[strlen(ch)-1] = 0;
}
char generateUserName(char email[50],char username[50]){
    for(int i=0;i<strlen(email);i++){
        if(email[i] == '@') break;
        else username[i] = email[i];
    }
}
int inptDta(void){
    int num;
    char input[50];
    printf("\n\t\tchoose an option:\t");
    fgets(input,sizeof(input),stdin);

    //remove newline ch
    input[strcspn(input, "\n")] = 0;

    //check if char are digits;
    int i;
    for(i=0; input[i] != '\0'; i++)
    {
        if(!isdigit(input[i])){
            printf("\n\t\t!!INVALID INPUT ");
            exit(1);
        }
    }

    // convert string to int
    num = atoi(input);
    // printf("you entered: %d\n",num);
    
    return num;
}