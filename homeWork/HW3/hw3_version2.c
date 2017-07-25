/*
* Program:	hw3_lnr7605.c	 Due Date: 10-02-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:  Using pointers, files, structs, and functions to compile a 
*		semi-database of employees. 
*		Use of typedeff struct to store the values of the text file in an array
*		calculate:
*			Gross Pay
*			Net Pay
*			Overall Number of Hours
*		Printing out Employee information formated in cells.
*		
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_EMP 100
#define MAX_DAYS 7
#define MAX_NAME_LEN 100

typedef struct {
	int EMP_ID;
	float PayRate, SSPCE, FEDPCE, STPCE, CTYPCE, hours, gross, net;
	float hoursWorked[MAX_DAYS];
	char empName[MAX_NAME_LEN];

} EMPLOYEE;

EMPLOYEE getEmp (FILE* InFile);
void printReportDetails();
void printReportHeading();

int main(int argc, char** argv) {
	EMPLOYEE empList[MAX_NUM_EMP];
	int count = 0;

	FILE *InFile;
	InFile = fopen("/home/dwooley/stu/empRecords.txt", "r");
	if (InFile == NULL) {
		printf("File Missing / Unable to Read.");
		return 1;
	}

	for (empList[count++]= getEmp(InFile); !feof(InFile); empList[count++] = getEmp(InFile));
	printReportHeading();	
	printReportDetails(empList, count);
	

	fclose(InFile);
	return 0;
}

EMPLOYEE getEmp(FILE *InFile) {
	
	float tmpHrs = 0.0;
	double placeHolder;
	float tempNet = 0;
	EMPLOYEE empRecord;
	
	
	fscanf(InFile, "%d", &empRecord.EMP_ID);//Employee ID
	
	
	
	fscanf(InFile, "%f", &tmpHrs); //Hours worked and loop 
	
	empRecord.hours = tmpHrs; //start of total hours worked
	for(int i = 0; tmpHrs > 0.01; i++){
		
		empRecord.hoursWorked[i] = tmpHrs;
		fscanf(InFile,"%f", &tmpHrs);
		if(tmpHrs == 0.0 || i>MAX_DAYS)
			break;

		placeHolder = empRecord.hoursWorked[i];
		empRecord.hours += placeHolder;//sum logic given to struct hours		
	}
	
	fscanf(InFile, "%f", &empRecord.PayRate); //Pay Rate
	
	empRecord.gross = empRecord.hours * empRecord.PayRate;
	
	fscanf(InFile, "%f", &empRecord.SSPCE); // Social Security %
	
	fscanf(InFile, "%f", &empRecord.FEDPCE); //Federal %
	
	fscanf(InFile, "%f", &empRecord.STPCE); //State %
	
	fscanf(InFile, "%f", &empRecord.CTYPCE); //City %
	
	empRecord.net = ((empRecord.gross *empRecord.SSPCE)+(empRecord.gross *empRecord.FEDPCE)+(empRecord.gross *empRecord.STPCE)+(empRecord.gross *empRecord.CTYPCE));
	tempNet = empRecord.net / 100;
	empRecord.net = empRecord.gross - tempNet;//Net Pay Calculation

	fscanf(InFile, "%[^\n]\n", empRecord.empName);//The Employee Name

	return empRecord;	
}

void printReportDetails(EMPLOYEE* empList, int empNum){
	int i;
	printf("    ID             Name            Gross    Net     SSw/h    ");
	printf("Fedw/h   Stw/h   Cityw/h   totHrs \n");
	printf(" 	                     Rate     h1      h2       h3     ");
	printf(" h4       h5       h6       h7 \n");
	printf(".------.------------------------.--------.--------.--------.");
	printf("--------.--------.--------.--------.\n");
	for(i = 0; i<empNum; i++){
	printf("|%5d | %-23s|%7.2f |%7.2f |%7.2f |%7.2f |%7.2f |%7.2f |%6.1f  |\n",
	empList[i].EMP_ID, empList[i].empName,empList[i].gross, empList[i].net, empList[i].SSPCE,
	empList[i].FEDPCE, empList[i].STPCE,empList[i].CTYPCE, empList[i].hours);
	printf("|      |                %7.2f |", empList[i].PayRate);
	for (int j=0; j<7; j++)
	printf("%6.1f  |", empList[i].hoursWorked[j]);
	printf("\n");
	printf("|------+------------------------+--------+--------+--------+");
	printf("--------+--------+--------+--------|\n");
	}
	printf("\"------\"------------------------\"--------\"--------\"--------\"");
	printf("--------\"--------\"--------\"--------\"\n");
	
}

void printReportHeading(){
	printf("COMP302                                          ");
        printf("                                     Lucas Reid\n");
	printf("Section 1                                        ");
        printf("                                     731791\n");
	printf("HomeWork 3                                       ");
        printf("                                     10/02/2016\n");
	
}
























