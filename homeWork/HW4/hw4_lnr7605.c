/*
* Program:	hw4_lnr7605.c	 Due Date: 10-16-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:  Process employee records from an external file. Compute Tax Witholdings and 
*		display in a database like output.
*			Use Pointers to dereference material given
*			add and impliment insertNewEmp(); funtion
*			
*			
*			
*		
*		
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_EMP 100
#define MAX_DAYS 7
#define MAX_NAME_LEN 100

typedef struct empPtr {
	int EMP_ID;
	float PayRate, SSPCE, FEDPCE, STPCE, CTYPCE, hours, gross, net;
	float SSwh, FEDwh, STwh,CTYwh;
	float hoursWorked[MAX_DAYS];
	char *empName;
	struct empPtr *empNext; 
	

} EMPLOYEE;

EMPLOYEE getEmp (FILE* InFile);

void printReportDetails(EMPLOYEE*);
void printReportHeading();
void insertNewEmp();

int main(int argc, char** argv) {
	EMPLOYEE *empList = NULL;
	EMPLOYEE *tempEmp;
	tempEmp = malloc(sizeof(EMPLOYEE));
	

	FILE *InFile;
	InFile = fopen("/home/dwooley/stu/empRecords.txt", "r");
	if (InFile == NULL) {
		printf("File Missing / Unable to Read.");
		return 1;
	}
	
	
	for (*tempEmp = getEmp(InFile); !feof(InFile); *tempEmp = getEmp(InFile)){
		
		insertNewEmp(&empList, tempEmp);		
	}
	
	printReportHeading();	
	printReportDetails(empList);

	fclose(InFile);
	return 0;
}

EMPLOYEE getEmp(FILE *InFile) {
	char *namePtr;
	char tempName[MAX_NAME_LEN];
	float tmpHrs = 0.0;
	double placeHolder;
	float tempNet = 0;
	int i = 0;

	EMPLOYEE *empRecord;
	empRecord = malloc(sizeof(EMPLOYEE));
	if(empRecord == NULL)
		return *empRecord;

	empRecord->empNext= NULL;
		
	fscanf(InFile, "%d", &empRecord->EMP_ID);//Employee ID
	if(feof(InFile))
		return *empRecord;		

	empRecord->hours = 0.0;
	fscanf(InFile, "%f", &tmpHrs);
	for(i; tmpHrs > 0.01; i++){	
		empRecord->hoursWorked[i] = tmpHrs;
		empRecord->hours += tmpHrs; //sum logic given to struct hours
		fscanf(InFile,"%f", &tmpHrs);
		
	}
	while(i<MAX_DAYS){
		empRecord->hoursWorked[i++] = 0.0;
	}

	fscanf(InFile, "%f", &empRecord->PayRate); //Pay Rate
	
	empRecord->gross = empRecord->hours * empRecord->PayRate;//calculated Gross income.
	
	fscanf(InFile, "%f", &empRecord->SSPCE); // Social Security %
	empRecord->SSwh = empRecord->gross * empRecord->SSPCE/100;
	
	fscanf(InFile, "%f", &empRecord->FEDPCE); //Federal %
	empRecord->FEDwh = empRecord->gross * empRecord->FEDPCE/100;
	
	fscanf(InFile, "%f", &empRecord->STPCE); //State %
	empRecord->STwh = empRecord->gross * empRecord->STPCE/100;
	
	fscanf(InFile, "%f", &empRecord->CTYPCE); //City %
	empRecord->CTYwh = empRecord->gross * empRecord->CTYPCE/100;
	
	empRecord->net = empRecord->gross - (empRecord->SSwh+empRecord->FEDwh+empRecord->STwh+empRecord->CTYwh);//netPay Calculation
			
	fscanf(InFile, "%[^\n]", tempName);
	namePtr = (char *) malloc(strlen(tempName)+1);
	strcpy(namePtr, tempName);
	empRecord->empName = namePtr;
	
	return *empRecord;	
}

void printReportDetails(EMPLOYEE* empList){
	int i=0;

	printf("    ID             Name            Gross    Net     SSw/h    ");
	printf("Fedw/h   Stw/h   Cityw/h   totHrs \n");
	printf(" 	                     Rate     h1      h2       h3     ");
	printf(" h4       h5       h6       h7 \n");
	printf(".------.------------------------.--------.--------.--------.");
	printf("--------.--------.--------.--------.\n");
	printf("|%5d | %-23s|%7.2f |%7.2f |%7.2f |%7.2f |%7.2f |%7.2f |%6.1f  |\n",	
	empList->EMP_ID, empList->empName,empList->gross, empList->net, empList->SSwh,
		empList->FEDwh, empList->STwh,empList->CTYwh, empList->hours);
		
		printf("|      |                %7.2f |", empList->PayRate);
		
		for (int j=0; j<MAX_DAYS; j++)
			printf(" %6.1f |", empList->hoursWorked[j]);
		printf("\n");
	
		for(empList = empList->empNext; empList!=NULL; empList=empList->empNext){
		//start with next
		// i=2  now becomes advance ptr; pter!=null; advanced ptr
		//emplist
		printf("|------+------------------------+--------+--------+--------+");
		printf("--------+--------+--------+--------|\n");
		printf("|%5d | %-23s|%7.2f |%7.2f |%7.2f |%7.2f |%7.2f |%7.2f |%6.1f  |\n",	
		empList->EMP_ID, empList->empName,empList->gross, empList->net, empList->SSwh,
		empList->FEDwh, empList->STwh,empList->CTYwh, empList->hours);
		
		printf("|      |                %7.2f |", empList->PayRate);

		for (int j=0; j<MAX_DAYS; j++)
			printf(" %6.1f |", empList->hoursWorked[j]);
		printf("\n");
		}

	printf("\"------\"------------------------\"--------\"--------\"--------\"");
	printf("--------\"--------\"--------\"--------\"\n");			
}

void printReportHeading(){
	printf("COMP302                                          ");
        printf("                                     Lucas Reid\n");
	printf("Section 1                                        ");
        printf("                                     731791\n");
	printf("HomeWork 4                                       ");
        printf("                                     10/16/2016\n");
	
}


void insertNewEmp (EMPLOYEE **head, EMPLOYEE *newEmp){
	
	EMPLOYEE *current;
	EMPLOYEE *previous;
	
	for(previous = current = *head; current !=NULL && current -> EMP_ID < newEmp ->EMP_ID; 	current = current -> empNext){
		previous = current;
	}
	newEmp -> empNext = current;
	if(current == *head)
		*head = newEmp;
	else
		previous->empNext=newEmp;
	
	
}	






















