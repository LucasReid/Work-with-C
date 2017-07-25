#ifndef GRADEBOOK_H_
#define GRADEBOOK_H_
#include <string>
using namespace std;

class GradeBook{
	
	private:
		int studentCount;
		int	quizCount;
		int	testCount;	
		double **quiz;
		double **test;
	public:
		GradeBook( string FileName );
		virtual ~GradeBook();
	
	public:
		void output();
		
	

};
#endif
