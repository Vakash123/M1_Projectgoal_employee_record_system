# Introduction:

This is a web application software for the employess who are working in an organization/Compnay. In this application we are having some feautres for the employees who are working in an organization. 


# Research: 

Employee Record System is software built to handle the primary housekeeping functions of a company. Employee Record System helps companies keep track of all the employees and their records. It is used to manage the company using a computerized system.


# Features :

In my Project there are some features which will be easy to the handler to store the organization data in their application 
 * Adding the employee data in the record 
 * Showing the List of all employees data in the record 
 * Modify the employee name in the records
 * Searching the employee name in the records
 * Delete the employee data in the record
 * Exit the application 


# Requirements: 

* visual code studio with C compiler
* Ubuntu (LINUX)
* Github (pushing the code)


# Swot analysis:

* Strength:

   * Add unlimited number of employee details in this application
   * After adding a particular employee details we can continue to add another employee details with yes/No option
   * Time saving for an organization to check for the employees data 
   * Removal of manual work for an organization related to employee record system
   * Accesable to delete the particual data by the name and other inputs by the admin
   * Accesable to modify the particual data by the name and other inputs by the admin
   * this application will update the data and show the output in a phased manner
   * Exit the application in an easier manner by providing Yes/No option

* Weakness:

   * Need not mention the space between two words (strings) 
   * we cannot search the particular employee detail in deeper manner

# 4W's and 1H

* Who: 
The IT team of an organization will work on this Employye Record system

* What:
To store employees data in an application 

* Where: 
In an application software

* When:
This project had started designed from 2nd of febrauary 2022

* How:
By selecting the neccesary option we can enter the input of an employee and store the information in an application

# Detail requirements 

 * High level requirements 
 
    Select anyone of the following: 
     * Add record
     * List record
     * modify record 
     * search record
     * Delete record 
     * Exit  

 * low level requirements 

     Enter the following information to the user 
      * Enter the name of employee
      * Enter the age of the employee
      * Enter the basic salary of the employee
      * Enter the employee experience in IT industry

# Best Method Follows

   * Had designed the software as a user frinedly to all the IT department who are dealing on record segment.
   Here I am mentioning the detal method of my software 

   * Add record: 
       *  In Add record section I had created a function called "Position".
       *  After adding the record you can type Y/N option to enter the new record.
         
   * List record:
       *  In list record section the output will be shown in a phased manner .
       *  In list record section the data will moves file cursor to start of the file called "perf".

   * Modify record:
       * Using the "strcmp", "fseek" and "fwrite" it will compare and override the list of records and will modify the current input provided by the user.
       * After modifying the particular record it will directly store it in the list of records.

   * Search record:
       * By providing the Emp_name of the user entire details of that employee name will be shown in the search record
       * If we had mentioned the wrong name in search record then the error message will be displayed to the user 
       * After the displaying the error message the software will provide an other chance to type Y/N option to enter the search record.

   * Delete record:
       *  had created a temp file to store the temporary data 
       *  Read all the record from the permenant file, If the data matches then it will store in temporary file the rest record wil store  it in permemant file
       *  After that we need to remove the original file and then rename the temp file name to original file name

   * Exit record: 
       * After completion of the usage of software you can exit the application by typing an option '6'
 


