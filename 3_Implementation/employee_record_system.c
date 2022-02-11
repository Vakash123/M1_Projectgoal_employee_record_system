#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <string.h>  
#include "position.h"

COORD coordinates = {0,0}; 
int main()
{
    FILE *permf, *tempf; 
    char option, c;
    
    struct emp
    {
        char ename[50]; 
        int eage; 
        float salary; 
    };

    struct emp e; 

    char empname[50]; 

    long int recsize; 
   
    int countsearch=0;
  
    system("Color E4"); 
    permf = fopen("EMPLOYEE.DAT","rb+");
    if(permf == NULL)
    {
        permf = fopen("EMPLOYEE.DAT","wb+");
        if(permf == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
       
    recsize = sizeof(e);
   
    while(1)
    {
        system("cls"); 
        position(40,7);
        printf( "WELCOME TO EMPLOYEE RECORD SYSTEM:\n");
        position(40,8);
        printf("----------------------------------");
        position(40,10); 
        printf("1. Add New employee Record"); 
        position(40,12);
        printf("2. List of all employee Records"); 
        position(40,14);
        printf("3. Modify employee Records"); 
        position(40,16);
        printf("4. Delete employee Records"); 
        position(40,18);
        printf("5. search employee Records"); 
        position(40,20);
        printf("6. Exit"); 
        position(40,22);
        printf("Your Choice: "); 
        fgetc(stdin); 
        c  = getche(); 
        switch(c)
        {
        case '1':  
            system("cls");
            fseek(permf,0,SEEK_END); 
            
            option = 'y';
            while(option == 'y')  
            {
                printf("\n Enter the Employee name: ");
                scanf("%s",e.ename);
                printf("\n Enter his/her age: ");
                scanf("%d", &e.eage);
                printf("\n Enter basic salary: ");
                scanf("%f", &e.salary);

                fwrite(&e,recsize,1,permf); 
                printf(" New Record had been added in your softare!\n");

                printf("\n want to add another record(y/n) ");
                fgetc(stdin); 
                option = getche(); 
            }
            break;
        case '2':
            system("cls");
            rewind(permf); 
            while(fread(&e,recsize,1,permf)==1)  
            {
            	printf("\nEnter the employee name: %s",e.ename);
            	printf("\nEnter the employee age: %d",e.eage);
            	printf("\nEnter the emplyee basic salary: %.2f",e.salary);                
            }
            getch();
            break;

        case '3':  
            system("cls");
            option = 'y';
            while(option == 'y')
            {
                printf("Enter the employee name to modify: ");
                scanf("%s", empname);
                rewind(permf);
                while(fread(&e,recsize,1,permf)==1)  
                {
                    if(strcmp(e.ename,empname) == 0)  
                    {
                        printf("\nEnter new name,age and salary: ");
                        scanf("%s%d%f",e.ename,&e.eage,&e.salary);
                        fseek(permf,-recsize,SEEK_CUR); 
                        fwrite(&e,recsize,1,permf); 
                        printf("Your record has been modified!\n");
                        break;
                    }
                }
                printf("\nDo you want to Modify another record(y/n)");
                fgetc(stdin);
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
                tempf = fopen("Temporary.dat","wb");  
                rewind(permf); 
                while(fread(&e,recsize,1,permf) == 1)  
                {
                    if(strcmp(e.ename,empname) != 0)  
                    {
                        fwrite(&e,recsize,1,tempf); 
                        
                    }
                   
                }
                fclose(permf);
                fclose(tempf);
                remove("EMPLOYEE.DAT"); 
                rename("Temporary.dat","EMPLOYEE.DAT"); 
                permf = fopen("EMPLOYEE.DAT", "rb+");
              
                printf("Do you want to Delete another record(y/n)");
                fgetc(stdin);
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
                tempf = fopen("Temporary.dat","wb");  
                rewind(permf); 
                while(fread(&e,recsize,1,permf) == 1)  
                {
                    if(strcmp(e.ename,empname) != 0)  
                    {
                        fwrite(&e,recsize,1,tempf); 
                        
                    }
                    
                }
                fclose(permf);
                fclose(tempf);
                remove("Temporary.dat"); 
                //rename("EMPLOYEE.DAT","Temporary.dat"); 
                permf = fopen("EMPLOYEE.DAT", "rb+");
                 //rewind(permf); 
                 
                  while(fread(&e,recsize,1,permf) == 1)  
                {
                	
                    if(strcmp(e.ename,empname) == 0)  
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
                fgetc(stdin);
                option = getche();
            }
            break;
		case '6':
            fclose(permf);  
            exit(0); /// 
        }
    }
    return 0;
}