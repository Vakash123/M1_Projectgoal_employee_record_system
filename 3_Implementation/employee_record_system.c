/**
 * @file employee_record_system.c
 * @author your name : Vankadari akash
 * @brief : Employee record sysytem is an web application software for the employess who are working in an organization/Compnay. In this application we are having some feautres for the employees who are working in an organization. 
 * @version 0.1
 * @date 2022-02-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// #include <stdio.h> ///for input output functions like printf, scanf
#include <stdlib.h>
#include <string.h>  ///string operations
#include "position.h"
/** List of Global Variable */
COORD coordinates = {0,0}; /// top-left corner of window

/** Main function started */

int main()
{
    FILE *permf, *tempf; /// file pointers
    char option, c;

    /** structure that represent a employee */
    struct emp
    {
        char ename[40]; ///name of employee
        int eage; /// age of employee
        float salary; /// basic salary of employee
    };

    struct emp e; /// structure variable creation

    char empname[40]; /// string to store name of the employee

    long int recsize; /// size of each record of employee
    //char cmp[40];
    int countsearch=0;

    /** open the file in binary read and write mode
    * if the file EMP.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    system("Color E4"); //E-yellow background color, 4-RED for text
    permf = fopen("EMP.DAT","rb+");
    if(permf == NULL)
    {
        permf = fopen("EMP.DAT","wb+");
        if(permf == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
    

    /// sizeo of each record i.e. size of structure variable e
    recsize = sizeof(e);

    /// infinite loop continues untile the break statement encounter
    while(1)
    {
        system("cls"); ///clear the console window
        position(40,7);
        printf( "WELCOME TO EMPLOYEE RECORD SYSTEM:\n");
        position(40,8);
        printf("----------------------------------");
        position(40,10); /// move the cursor to postion 40, 10 from top-left corner
        printf("1. Add Record"); /// option for add record
        position(40,12);
        printf("2. List Records"); /// option for showing existing record
        position(40,14);
        printf("3. Modify Records"); /// option for editing record
        position(40,16);
        printf("4. Delete Records"); /// option for deleting record
        position(40,18);
        printf("5. search Records"); /// exit from the program
        position(40,20);
        printf("6. Exit"); /// exit from the program
        position(40,22);
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        c  = getche(); /// get the input from keyboard
        switch(c)
        {
        case '1':  /// if user press 1
            system("cls");
            fseek(permf,0,SEEK_END); /// search the file and move cursor to end of the file   //fseek() in C is used to change the file pointer (in order to point to a specific file position) to the desired location.
            /// here 0 indicates moving 0 distance from the end of the file

            option = 'y';
            while(option == 'y')  /// if user want to add option record
            {
                printf("\n Enter the Employee name: ");
                scanf("%s",e.ename);
                printf("\n Enter his/her age: ");
                scanf("%d", &e.eage);
                printf("\n Enter basic salary: ");
                scanf("%f", &e.salary);

                fwrite(&e,recsize,1,permf); /// write the record in the file
                printf(" New Record added!\n");

                printf("\n Do you want to add another record(y/n) ");
                fflush(stdin); //he function fflush (stdin) is used to flush the output buffer of the stream. It returns zero, if successful otherwise, returns EOF and feof error indicator is set.
                option = getche(); //waits for any character input from keyboard
            }
            break;
        case '2':
            system("cls");
            rewind(permf); ///this moves file cursor to start of the file
            while(fread(&e,recsize,1,permf)==1)  /// read the file and fetch the record one record per fetch
            {
            	printf("\nEnter the employee name: %s",e.ename);
            	printf("\nEnter the employee age: %d",e.eage);
            	printf("\nEnter the emplyee basic salary: %.2f",e.salary);
                
            }
            getch();
            break;

        case '3':  /// if user press 3 then do modify record
            system("cls");
            option = 'y';
            while(option == 'y')
            {
                printf("Enter the employee name to modify: ");
                scanf("%s", empname);
                rewind(permf);
                while(fread(&e,recsize,1,permf)==1)  /// fetch all record from file
                {
                    if(strcmp(e.ename,empname) == 0)  ///if entered name matches with that in file
                    {
                        printf("\nEnter new name,age and salary: ");
                        scanf("%s%d%f",e.ename,&e.eage,&e.salary);
                        fseek(permf,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                        fwrite(&e,recsize,1,permf); /// override the record
                        printf("Your record has been modified!\n");
                        break;
                    }
                }
                printf("\nDo you want to Modify another record(y/n)");
                fflush(stdin);
                option = getche();
            }
            break;
        case '4':
            system("cls");
            option = 'y';
            while(option == 'y')
            {
                printf("\nEnter name of employee to delete: ");
                scanf("%s",empname);
                tempf = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                rewind(permf); /// move record to starting of file
                while(fread(&e,recsize,1,permf) == 1)  /// read all records from file
                {
                    if(strcmp(e.ename,empname) != 0)  /// if the entered record match
                    {
                        fwrite(&e,recsize,1,tempf); /// move all records except the one that is to be deleted to temp file
                        
                    }
                   
                }
                fclose(permf);
                fclose(tempf);
                remove("EMP.DAT"); /// remove the orginal file
                rename("Temp.dat","EMP.DAT"); /// rename the temp file to original file name
                permf = fopen("EMP.DAT", "rb+");
              
                printf("Do you want to Delete another record(y/n)");
                fflush(stdin);
                option = getche();
            }
            break;
        case '5':
        	system("cls");
        	option ='y';
        	while(option =='y')
			{
                printf("\nEnter name of employee to Search: ");
                scanf("%s",empname);
                tempf = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                rewind(permf); /// move record to starting of file
                while(fread(&e,recsize,1,permf) == 1)  /// read all records from file
                {
                    if(strcmp(e.ename,empname) != 0)  /// if the entered record match
                    {
                        fwrite(&e,recsize,1,tempf); /// move all records except the one that is to be deleted to temp file
                        
                    }
                    
                }
                fclose(permf);
                fclose(tempf);
                remove("Temp.dat"); /// remove the orginal file
                //rename("EMP.DAT","Temp.dat"); /// rename the temp file to original file name
                permf = fopen("EMP.DAT", "rb+");
                 //rewind(permf); ///this moves file cursor to start of the file
                 
                  while(fread(&e,recsize,1,permf) == 1)  /// read all records from file
                {
                	
                    if(strcmp(e.ename,empname) == 0)  /// if the entered record match
                    {
                        printf("Enter the employee name: %s",e.ename);
            	        printf("\nEnter the employee age: %d",e.eage);
            	        printf("\nEnter the emplyee basic salary: %.2f\n",e.salary);
            	        countsearch++;
                    }
                   
                   
                }
                if(countsearch==0)
				{
				printf("Record not found!!\n");
				}
                countsearch=0;
                printf("\nDo you want to Search another record?(y/n)");
                fflush(stdin);
                option = getche();
            }
            break;
		case '6':
            fclose(permf);  /// close the file
            exit(0); /// exit from the program
        }
    }
    return 0;
}
