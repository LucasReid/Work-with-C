#include "GradeBook.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

GradeBook::GradeBook( string FileName ){
	//open the file for reading
	//File operatins cannot accept strings
	//so you must convert the string to a char*
	
	ifstream 	InFile( FileName.c_str() );
	
	//initialize the data members
	studentCount = -1;
	quizCount = -1;
	testCount = -1;
	
	
	
	//read in the student count
	InFile>>studentCount;
	InFile>>quizCount;
	InFile>>testCount;
	
	
	
	//first dimension
	quiz = new double * [studentCount];
	//second dimension
	for(int i =0; i< studentCount; i++)
		quiz[i] = new double[quizCount];
	
	
	//test scores 
	test = new double * [studentCount];
	//second dimension
	for(int i =0; i< studentCount; i++)
		test[i] = new double[testCount];
	
	
	for(int i=0; i<studentCount; i++){
		//read student number
		//number is not stored here
		//used for a pointer 
		int studentNum;
		InFile>>studentNum;
		
		//read in for each of the quiz scores
		for(int j=0; j< quizCount; j++)
			InFile>>quiz[i][j];
		
	}
	
	for(int i=0; i<studentCount; i++){
		int studentNum;
		InFile>>studentNum;
		
		for(int j=0; j<testCount; j++){
			InFile>>test[i][j];
		}
	}
	
	//close file
	InFile.close();
}
void GradeBook::output(){

	string outFileName;
	
	cout<<"Enter the output filename (include the .txt)\n"; 
	cin>>outFileName;
	cout<<"7"<<endl;
	//display the name as verification
	cout<<"You entered the filename: "<<outFileName<<"\n";
	
	//Open the file
	ofstream outFile(outFileName.c_str());
	
	//output the data to the file!
	for(int i =0; i<studentCount; i++){
		for(int j =0; j<quizCount; j++){
			outFile<<setw(8)<<fixed<<setprecision(2)<<quiz[i][j]; 
		}
		outFile<<endl;
	}
	outFile.close();
	return;
}
GradeBook::~GradeBook(){
	//delet the test array 
	//start with second dimension
	for(int i=0; i<studentCount; i++)
		delete [] test[i];
	//followed by acending dimensions
	delete [] test;
	
	for(int i=0; i<studentCount; i++)
		delete [] quiz[i];
		
		delete [] quiz;
}




























