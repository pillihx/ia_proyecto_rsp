#ifndef SOLUTIONMEDICO_H
#define SOLUTIONMEDICO_H

#include<iostream>
#include<string.h>
#include<vector>
#include "Instance.hpp"

using namespace std;

struct solutionMedicoStruct{
  int paciente;
  int tipoPaciente;
  int dia;
  int bloque;
  int medico;
  int maquina;
};

vector<solutionMedicoStruct> asignarMedico(instanceStruct);

//Check contraints
bool validateIntegrity(instanceStruct currentInstance,int i_p,int tipoPaciente,int i_d,int i_b,int i_m);
//Funtions validations
bool disponibilityMed(instanceStruct currentInstance,int i_m,int i_d,int i_b);
bool ocupadoMed(instanceStruct currentInstance,int i_m,int i_d,int i_b);
bool checkWaitTimes(instanceStruct currentInstance,int tipoPaciente,int i_p,int i_d);
//Function assign solution
void assignToPatient(int tipoPaciente,int i_p,int i_d,int i_b,int i_m);

#endif
