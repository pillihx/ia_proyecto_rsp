#ifndef PRINTRESULT_H
#define PRINTRESULT_H

#include<iostream>
#include<string>
#include<vector>
#include "SolutionMedico.hpp"
#include "Instance.hpp"

using namespace std;

void printResult(instanceStruct currentInstance,vector<solutionMedicoStruct> asignacion,int d_min,int d_max);
int findValue(vector<solutionMedicoStruct> asignacion,int i_p,int i_d,int i_b);

#endif
