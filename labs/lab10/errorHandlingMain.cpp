#include "errorHandling.h"
#include <iostream>
#include <stdexcept>
#include <ifstream>
using namespace std;

int main(int argc, char** argv){
	errorHandling	ER;
	ER.errorTesting();
	ER.exceptionTesting();
	return 0;
}
