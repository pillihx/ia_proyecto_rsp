#include<iostream>
#include<string.h>
#include<vector>

#include "Instance.hpp"
#include "SolutionMedico.hpp"
#include "PrintResult.hpp"

using namespace std;

int main(int argc, char* argv[]){
	string pathInstance = argv[1];
	instanceStruct currentInstance = readInstance(pathInstance);

	vector<solutionMedicoStruct> asignacion = asignarMedico(currentInstance);

	printResult(currentInstance,asignacion,0,5);//primera semana
	printResult(currentInstance,asignacion,7,12);//segunda semana
	printResult(currentInstance,asignacion,14,19);//tercera semana
	printResult(currentInstance,asignacion,21,26);//cuarta semana

	return 0;
}
