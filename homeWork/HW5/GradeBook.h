#ifndef GRADEBOOK_H_
#define GRADEBOOK_H_
#include <string>

using namespace std;

class GradeBook{
	
	private:
		double 	quizWeight;
		double	testWeight;
		double	qMax;
		double 	qMin;
		double	tMax;
		double 	tMin;
		double	qAvg;
		double 	tAvg;
	private:	
		int	studentCount;
		
		int 	quizCount;
		int 	testCount;
		int 	studentID;
		int	*ID;
	private:		
		double 	**quiz;
		double	**test;	
		double	*totalQuiz;
		double 	*totalTest;
	private:
		double 	*wQuiz;
		double	*quizPercent;
		double 	*wTest;
		double	*testPercent;
		double 	*overall;
		
	private:	
		string	className;
		string  fName;
		string  lName;
		string *studentName;
		
		
	public:
		GradeBook( string FileName );
		virtual ~GradeBook();
	
	public:
		void calculateStudentGrades();
		
	public:
		void printClassStats();
		void printStudentGrades(); 
		
	

};
#endif
