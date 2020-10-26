/*
* Project Name: Bank Management System
* Author: Mahamudul Hasan
* Email: hasaneee717@gmail.com
* Programming Language: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main_text;
void menu();
struct date{
    int month,day,year;
};
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

}add,upd,check,rem,transaction;

float intarest(float amount, int rate, float time){
    float SI;
    SI = (amount*rate*time)/100;
    return SI;
}

void delay(int i){
    int j, k;
    for(j = 0; j<i; j++){
        k = j;
    }
}
void new_acc(){
    int choice;
    FILE *ptr;
    acc_no:
        ptr = fopen("record.dat", "a+");
        system("cls");
        printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 Add Account \xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\n\t\t Enter Today's Date (dd/mm/yyyy):");
        scanf("%d/%d/%d", &add.deposit.day, &add.deposit.month, &add.deposit.year);
        printf("\nEnter Account No: ");
        scanf("%d", &check.acc_no);

        while(fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF){
            if(check.acc_no == add.acc_no){
                printf("\nAccount is already exists!");
                delay(100000);
                system("cls");
                goto acc_no;
            }
        }

        add.acc_no = check.acc_no;
        printf("\nEnter your name: ");
        scanf("%s", &add.name);
        printf("\nEnter Date of Birth(dd/mm/yy): ");
        scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);
        printf("\nEnter your address: ");
        scanf("%s", add.address);
        printf("\nEnter your phone number: ");
        scanf("%lf", &add.phone);
        printf("\nEnter your Citizenship: ");
        scanf("%s", &add.citizenship);
        printf("\nEnter the ammount you deposit: ");
        scanf("%f", &add.amt);
        printf("\nAccount Type: \n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice: ");
        scanf("%s", &add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        fclose(ptr);
        printf("\nAccount Creat Successfull!");
        add_invalid:
            printf("\n\n\t\tEnter 1 goto Main Menu and 0 to exit.");
            scanf("%d", &main_text);
            if(main_text == 1){
                system("cls");
                menu();
            } else if(main_text == 0){
                system("cls");
                close();
            } else{
                printf("\n\t\tInvalid");
                system("cls");
                goto add_invalid;
            }

}
void edit(){
    int update_info, i = 0, test = 0;
    FILE *old_file, *new_file;
    update_acc:
    old_file = fopen("record.dat", "r");
    new_file = fopen("new.dat", "w");
    printf("Enter your account no: ");
    scanf("%d", &upd.acc_no);
    while(fscanf(old_file, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF){
        if(upd.acc_no == add.acc_no){
            test = 1;
            printf("Which information you want to update? 1. Address, 2. Phone number");
            scanf("%d", &update_info);
            if(update_info == 1){
                printf("Enter new address: ");
                scanf("%s", &upd.address);
                fprintf(new_file, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Update Successfull!");
                delay(100000000);
                system("cls");
            } else if(update_info == 2){
                printf("Enter new Phone number: ");
                scanf("%f", &upd.phone);
                fprintf(new_file, "%d %s %d/%d/%d %d %s %s %f %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Update Successfull!");
                delay(100000000);
                system("cls");
            } else{
                fprintf(new_file,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
        }
    }
    fclose(old_file);
    fclose(new_file);
    remove("record.dat");
    rename("new.dat", "record.dat");

      if(test != 1){
        printf("Account number not match. Try again..");
        delay(1000000000);
        system("cls");
        i++;
        if(i == 3){
            system("cls");
            menu();
        }
        goto update_acc;
    } else {
        add_invalid:
        printf("\n\n\t\tEnter 1 goto MainMenu and 0 to exit.");
        scanf("%d", &main_text);
        if(main_text == 1){
            system("cls");
            menu();
        } else if(main_text == 0){
            system("cls");
            close();
        } else{
            printf("\n\t\tInvalid");
            system("cls");
            goto add_invalid;
        }
    }
}
void transact(){
    int test = 0, trans_num, i = 0;
    FILE *tran_ptr, *new_tran_ptr;
    trans_upd:
    tran_ptr = fopen("record.dat", "r");
    new_tran_ptr = fopen("new.dat", "w");
    printf("\n\n\n\t\tEnter your Password: ");
    scanf("%d", &transaction.acc_no);
    while(fscanf(tran_ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF){
        if(transaction.acc_no == add.acc_no){
            test = 1;
            if(strcmpi(add.acc_type, "Fixed1") == 0 || strcmpi(add.acc_type, "Fixed2") == 0 || strcmpi(add.acc_type, "Fixed3") == 0){
                printf("You cannot deposit or withdraw money from Fixed account");
                delay(100000000);
                system("cls");
                menu();
            }
            printf("\n\n\t\t1.Deposit\n\n\t\t2.Withdraw");
            scanf("%d", &trans_num);
            if(trans_num == 1){
                printf("\n\n\t\tYour total money: %f", add.amt);
                printf("\n\t\tEnter deposit amount: ");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(new_tran_ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,&add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\t\tNow Your total money: %f", add.amt);
                printf("\n\n\t\tDeposit SuccessFull!");
                delay(100000000);
            }
            else if(trans_num == 2){
                printf("\n\n\t\tYour total money: %f", add.amt);
                printf("\n\n\t\tEnter withdraw amount: ");
                scanf("%f", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(new_tran_ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\t\tNow Your total money: %f", add.amt);
                printf("\n\n\t\tDeposit SuccessFull!");
                delay(100000000);
            } else{
                fprintf(new_tran_ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

            }
        }
    }
    fclose(tran_ptr);
    fclose(new_tran_ptr);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if(test!=1){
        printf("Account number not match. Try again..");
        delay(1000000000);
        system("cls");
          add_invalid:
        printf("\n\n\t\tSelect 1 for MainMenu 0 for exit");
        scanf("%d", &main_text);
        if(main_text == 1){
            system("cls");
            menu();
        } else if(main_text == 0){
            system("cls");
            close();
        } else{
            printf("\n\n\t\tPlease Select 1 or 0");
            delay(100000000);
            system("cls");
            goto add_invalid;
        }
    } else{
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_text);
        system("cls");
        if (main_text==1)
            menu();
        else
            close();
    }
}
void see(){
    FILE *ptr;
    ptr = fopen("record.dat", "r");
    int test, rate, choice;
    float time, intrst;
    printf("\n\n\nDo you want to check by 1.Account  Name 2.Name. Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 1){
        printf("\n\n\\Enter your ACC No: ");
        scanf("%d", &check.acc_no);
        while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF){
            if(add.acc_no == check.acc_no){
                system("cls");
                test = 1;
                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type, "Fiexed1") == 0){
                    rate = 9;
                    time = 1.0;
                    intrst = intarest(add.amt, rate, time);
                    printf("\nyou wil get $%.2lf as Intarest on %d/%d/%d", intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                } else if(strcmpi(add.acc_type, "Fixed2") == 0){
                    rate = 11;
                    time = 2.0;
                    intrst = intarest(add.amt, rate, time);
                    printf("\nyou wil get $%.2lf as Intarest on %d/%d/%d", intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
                } else if(strcmpi(add.acc_type, "Fixed3") == 0){
                    rate = 13;
                    time = 3.0;
                    intrst = intarest(add.amt, rate, time);
                    printf("\nyou wil get $%.2lf as Intarest on %d/%d/%d", intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
                } else if(strcmpi(add.acc_type, "Saving") == 0){
                    rate = 8;
                    time = 1.0/12.0;
                    intrst = intarest(add.amt, rate, time);
                    printf("\nyou wil get $%.2lf as Intarest on %d/%d/%d", intrst,add.deposit.month,add.deposit.day,add.deposit.year);
                } else if(strcmpi(add.acc_type,"Current") == 0){
                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    } else if(choice == 2){
        printf("\n\nEnter your Name: ");
        scanf("%s", &check.name);
        while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF){
            if(check.name == add.name){
                system("cls");
                test = 1;
                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type, "fixed1") == 0){
                    rate = 9;
                    time = 1.0;
                    intrst = intarest(add.amt, rate, time);
                    printf("\nyou wil get $%.2lf as Intarest on %d/%d/%d", intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                } else if(strcmpi(add.acc_type, "fixed2") == 0){
                    rate = 11;
                    time = 2.0;
                    intrst = intarest(add.amt, rate, time);
                    printf("\nyou wil get $%.2lf as Intarest on %d/%d/%d", intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
                } else if(strcmpi(add.acc_type, "fixed3") == 0){
                    rate = 13;
                    time = 3.0;
                    intrst = intarest(add.amt, rate, time);
                    printf("\nyou wil get $%.2lf as Intarest on %d/%d/%d", intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
                } else if(strcmpi(add.acc_type, "saving") == 0){
                    rate = 8;
                    time = 1.0/12.0;
                    intrst = intarest(add.amt, rate, time);
                    printf("\nyou wil get $%.2lf as Intarest on %d/%d/%d", intrst,add.deposit.month,add.deposit.day,add.deposit.year);
                } else if(strcmpi(add.acc_type,"current") == 0){
                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }
    fclose(ptr);
    if(test == 0){
        invalid:
            printf("\n\nNo Information found about this Account.");
            printf("\n\nType 1 for goto main menu 0 for close: ");
            scanf("%d", &main_text);
            if(main_text == 1){
                system("cls");
                menu();
            } else if(main_text == 0){
                system("cls");
                close();
            } else{
                system("cls");
                goto invalid;
            }
    } else{
           printf("\n\nType 1 for goto main menu 0 for close: ");
            scanf("%d", &main_text);
            if(main_text == 1){
                system("cls");
                menu();
            }
            else{
                system("cls");
                close();
            }
    }

}
void erase(){
    FILE *old_file, *new_file;
    old_file = fopen("record.dat", "r");
    new_file = fopen("new.dat", "w");
    int test = 0;
    printf("\n\n\t\t\tEnter your ACC No: ");
    scanf("%d", &rem.acc_no);
    while(fscanf(old_file, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF){
        if(rem.acc_no != add.acc_no){
            fprintf(new_file, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        } else{
            printf("\n\n\t\tRECORD DELETE SUCCESSFULLY");
            delay(10000000);
            test++;
        }
    }
    fclose(old_file);
    fclose(new_file);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if(test == 0){
        printf("\n\n\t\t\tRECORD NOT FOUND");
        erase_invalid:
        printf("\n\n\t\tEnter 1 to try again or enter 2 to go Main menu or Enter 0 to Exit");
        scanf("%d", &main_text);
        if(main_text == 1){
            system("cls");
            erase();
        } else if(main_text == 2){
            system("cls");
            menu();
        } else if(main_text == 0){
            system("cls");
            close();
        } else{
            printf("\n\n\t\tInvalid!!");
            delay(100000000);
            goto erase_invalid;
        }
    } else{
        printf("\n\n\t\tEnter 1 to goto Main Menu and 0 to exit");
        scanf("%d", &main_text);
        if(main_text == 1){
            system("cls");
            menu();
        } else{
            system("cls");
            close();
        }
    }
}
void view_list(){
    int test = 0;
    FILE *view;
    view = fopen("record.dat", "r");
    system("cls");
    printf("\nACC NO\t\tName\t\t\tAddress\t\t\t\tPhone\t\t\tACC Type");
    while(fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF){
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf\t\t\t%s",add.acc_no,add.name,add.address,add.phone, add.acc_type);
        test++;
    }
    fclose(view);
    if(test == 0){
        printf("\nRECORD NOT FOUND!!");
        add_invalid:
        printf("\n\t\tEnter 0 to close Or Enter 1 to go Main Menu");
        scanf("%d", &main_text);
        if(main_text == 0){
            system("cls");
            close();
        } else if(main_text == 1){
            system("cls");
            menu();
        } else{
            printf("\n\t\t\tYou Enter invalid number.");
            system("cls");
            goto add_invalid;
        }
    } else {
        printf("\n\t\tEnter 0 to close Or Enter 1 to go Main Menu");
        scanf("%d", &main_text);
        if(main_text == 1){
            system("cls");
            menu();
        } else{
            system("cls");
            close();
        }
    }

}
void close(){
    printf("\n\n\n\nThis C Mini Project is developed by Mahamudul Hasan!");
}

void menu(){
    int choice;
    system("cls");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 Banking Management System \xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\tWelcome to Main Menu");
    printf("\n\n\t\t1. Create Account\n\n\t\t2. Edit Information\n\n\t\t3. For Transactions\n\n\t\t4. Check the details of existing account\n\n\t\t5. Remove Account \n\n\t\t6. View customer's list \n\n\t\t7. Exit\n\n\n\n\t\t Enter your choice: ");
    scanf("%d", &choice);

    system("cls");
    switch(choice){
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;
        default:
            printf("\n\n\t\t\tWrong number type.");
            delay(1000000000);
            menu();
    }
}

int main()
{
    char pass[10];
    char main_pass[10] = "hasan";
    printf("\n\n\tEnter your Password: ");
    scanf("%s", pass);
    if(strcmp(pass, main_pass) == 0){
        printf("\n\tLogin Successful. Loading");
        for(int i = 0; i<6; i++){
            delay(1000000);
            printf(".");
        }
        system("cls");
        menu();
    }
    else{
        system("cls");
        printf("Invalid\n");
        login_try:
            printf("Enter 1 for try again and 0 for exit.");
            scanf("%d", &main_text);
            if(main_text == 1){
                system("cls");
                main();
            } else if(main_text == 0){
                system("cls");
                close();
            } else{
                system("cls");
                printf("Invalid!");
                delay(1000000);
                system("cls");
                goto login_try;
            }
    }
    printf("\n\n");

    return 0;
}
