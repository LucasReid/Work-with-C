#include "GradeBook.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

GradeBook::GradeBook( string FileName ){
	//open the file for reading
	//File operatins cannot accept strings
	//so you must convert the string to a char*
	
	ifstream 	InFile( FileName.c_str() );
	
	//initialize the data members
	quizWeight = -1;
	testWeight =-1;
	
	studentCount = -1;
	quizCount = -1;
	testCount = -1;
		
	//read in the student count
	getline(InFile, className);	
	InFile>>quizWeight;
	InFile>>testWeight;		
	InFile>>studentCount;
	InFile>>quizCount;
	InFile>>testCount;
	
	//stat variables. 

	
	
	quiz = new double * [studentCount];
	for(int i =0; i< studentCount; i++)
		quiz[i] = new double[quizCount];
		
	test = new double * [studentCount];
	for(int i =0; i< studentCount; i++)
		test[i] = new double[testCount];
			
	ID = new int [studentCount];
	studentName = new string[studentCount];
	
	//array Block
	totalQuiz = new double [studentCount];
	totalTest = new double [studentCount];
	wQuiz = new double[studentCount];
	quizPercent = new double [studentCount];
	wTest = new double[studentCount];
	testPercent = new double [studentCount];
	overall = new double[studentCount];
	
	
	for(int i=0; i< studentCount; i++){
		InFile>>ID[i];
		
		//start quiz calculations
		qMax = quiz[i][0];
		qMin = quiz[i][0];
		
		
		for(int j=0; j<quizCount; j++){
			InFile>>quiz[i][j];
			totalQuiz[i] +=quiz[i][j];
			
			//TODO MAX
			if(quiz[i][j]> qMax){
				qMax = quiz[i][j];
			}
			if(quiz[i][j]< qMin){
				qMin = quiz[i][j];
			}
		}
		quizPercent[i] = (totalQuiz[i]/quizCount);
		wQuiz[i] = (quizPercent[i]*(quizWeight/100));
		qAvg +=quizPercent[i];
		
		//start test calculations
		//tMax = test[i][0];	
		for(int j=0; j<testCount; j++){
		tMax = test[i][0];
		tMin = test[i][0];
			InFile>>test[i][j];
			totalTest[i] += test[i][j];
			if(test[i][j]>tMax){
				tMax = test[i][j];
			}
			if(test[i][j]<tMin){
				tMin = test[i][j];
			}
					
		}
		testPercent[i] = (totalTest[i]/testCount);
		wTest[i] = (testPercent[i]*(testWeight/100));
		tAvg+=testPercent[i];
		
		overall[i] = wTest[i] + wQuiz[i];
		getline(InFile, studentName[i]);
				
	}
	qAvg = qAvg/studentCount;
	tAvg = tAvg/studentCount;		
	//close file
	InFile.close();
}
GradeBook::~GradeBook(){
	//delet the test array 
	//start with second dimension
	
	//followed by acending dimensions
	delete [] ID;	
	for(int i=0; i<studentCount; i++)
		delete [] quiz[i];
		delete [] quiz;

	for(int i=0; i<studentCount;i++)
		delete [] test[i];
		delete [] test;
	delete [] studentName;
	delete [] totalQuiz;
	delete [] totalTest;	
	
		
}

void GradeBook::printClassStats(){
	//TODO
	//output file
	string outFileName;
	
	outFileName = className+"_ClassStats.txt";
	ofstream outFile(outFileName.c_str());
	outFile<<"Class Stats"<<endl;
	outFile<<"Quiz Stats"<<endl;
	outFile<<"MAX: "<<qMax<<endl;
	outFile<<"MIN: "<<qMin<<endl;
	outFile<<"AVG: "<<qAvg<<endl;
	outFile<<"--------------------------------------"<<endl;
	outFile<<"Test Stats"<<endl;
	outFile<<"MAX: "<<tMax<<endl;
	outFile<<"MIN: "<<tMin<<endl;
	outFile<<"AVG: "<<tAvg<<endl;
	
	outFile<<"\n\n\n"<<endl;
	outFile<<"Quiz Scores"<<endl;
	for(int i =0; i<studentCount; i++){
		outFile<<"Student ID: "<<ID[i]<<" Student Name: "<<studentName[i]<<endl;
		for(int j =0; j<quizCount; j++)
			outFile<<quiz[i][j]<<" ";
			
		outFile<<"\n\n"<<endl;
			
		
	}
	outFile<<"----------------------------------------------------------------------"<<endl;
	outFile<<"\n\n"<<endl;
	outFile<<"Test Scores"<<endl;
	for(int i =0; i<studentCount; i++){
		outFile<<"Student ID: "<<ID[i]<<" Student Name: "<<studentName[i]<<endl;
		for(int j =0; j<testCount; j++)
			outFile<<test[i][j]<<" ";
			
		outFile<<"\n\n"<<endl;
			
		
	}
}

void GradeBook::printStudentGrades(){
	//TODO
	//output file
	string 	outFileName;
	char	letterGrade;      
	
	outFileName = className+"_StudentGrades.txt";
	
	//outFileName<<className<<"_"<<"ClassStats.txt";
	ofstream outFile(outFileName.c_str());
	outFile<<className<<endl;
	outFile<<"Quiz Weight: "<<quizWeight<<"%"<<endl;
	outFile<<"Test Weight: "<<testWeight<<"%"<<endl;	
////////////////////////////////////////////////////////////////////////////////////////////////
//start of quiz scores
	
	outFile<<"Overall Marks for the class "<<className<<endl;
	outFile<<"studentID		StudentName		  Class Grade		Grade"<<endl;
		outFile<<"---------		-----------		-----------		------"<<endl;			 			
		
		for(int i=0; i <studentCount;i++){

			if(overall[i]>=90)
				letterGrade = 'A';
			else if(overall[i]>=80 && overall[i]<90)
				letterGrade = 'B';
			else if(overall[i]>=70 && overall[i]<80)
				letterGrade = 'C';
			else if(overall[i]>=60 && overall[i]<70)
				letterGrade = 'D';		
			else if(overall[i]>=0 && overall[i]<60)
				letterGrade = 'E';
				
			outFile<<ID[i]<<"			"<<studentName[i]<<"			"<<letterGrade<<"		"<<overall[i]<<endl;
			
			//outFile<<studentName[i]<<endl;
		}

}




























