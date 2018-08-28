#include<iostream>
#include "SolutionMedico.hpp"
/*
  Funcion para realizar la asignacíón de medicos, considerando
  nPacientes = el número de pacientes a tratar
  nDías = Cantidad de días a planificar
  nBloques = Cantidad de bloques por día, según el Tiempo de Tratamiento
*/
int i_p,i_d,i_b,i_m,tipoPaciente;
vector<solutionMedicoStruct> asignacion;

vector<solutionMedicoStruct> asignarMedico(instanceStruct currentInstance){
  for(i_p=0; i_p<currentInstance.nPacientes; i_p++){//Iterar sobre cantidad de Pacientes
    if(i_p < currentInstance.NpacR)
      tipoPaciente = 0;
    if( i_p >= currentInstance.NpacR && i_p < (currentInstance.NpacP + currentInstance.NpacR))
      tipoPaciente = 1;
    if( i_p >= (currentInstance.NpacP + currentInstance.NpacR) && i_p < (currentInstance.NpacU + currentInstance.NpacP))
      tipoPaciente = 2;
    for(i_d=0; i_d<currentInstance.nDias; i_d++){//Iterar sobre cantidad de Dias
      for(i_b=0; i_b<currentInstance.nBloques; i_b++){//Iterar sobre cantidad de Bloques
        for(i_m=0; i_m<currentInstance.nDoctores; i_m++){//Iterar sobre cantidad de Doctores
          if(validateIntegrity(currentInstance,tipoPaciente,i_p,i_d,i_b,i_m)){
            assignToPatient(tipoPaciente,i_p,i_d,i_b,i_m);
            break;
          }
          else{
            if(i_m == currentInstance.nDoctores - 1){
              //SI Ninguno de los doctores puede responder la necesidad de atencion al paciente
              assignToPatient(tipoPaciente,i_p,i_d,i_b,-1);
              break;
            }
          }
        }
      }
    }
  }
  return asignacion;
}
bool validateIntegrity(instanceStruct currentInstance,int tipoPaciente,int i_p,int i_d,int i_b,int i_m){
  /*
  Funcion para verificar las diferentes restricciones del problema de
  Radiotherapy Scheduling Problem
  */
  //verificar que el tratamiento del paciente esté dentro de los limites
  if(!checkWaitTimes(currentInstance,tipoPaciente,i_p,i_d))
    return false;
  //verificar disponibilidad del medico
  if(!disponibilityMed(currentInstance,i_m,i_d,i_b))
    return false;
  //verificar si el medico está ocupado
  if(!ocupadoMed(currentInstance,i_m,i_d,i_b))
    return false;

  return true;
}
bool ocupadoMed(instanceStruct currentInstance,int i_m,int i_d,int i_b){
  //CHEQUEAR SI EL DOCTOR NO ESTÁ YA OCUPADO EN ESE DÍA Y Bloque con otro PACIENTE
  for(int i=0; i<asignacion.size(); i++){
    if(asignacion[i].medico == i_m && asignacion[i].dia == i_d && asignacion[i].bloque == i_b)
      return false;
  }
  return true;
}
bool checkWaitTimes(instanceStruct currentInstance,int tipoPaciente,int i_p,int i_d){
  //funcion que asegura que el tratamiento del paciente esté dentro de los limites establecidos según el Tipo de Paciente
  int dayTemp=-1;
  for(int i=0; i<asignacion.size(); i++){
    if(asignacion[i].paciente == i_p && asignacion[i].dia > dayTemp)
      dayTemp = asignacion[i].dia;
  }
  if(dayTemp != -1){
    int differenceDays = i_d - dayTemp;
    if(tipoPaciente == 0){
      if(differenceDays < currentInstance.tiemposAtencionRadicales[0])
        return false;
    }
    if(tipoPaciente == 1){
      if(differenceDays < currentInstance.tiemposAtencionPaliativos[0])
        return false;
    }
    if(tipoPaciente == 2){
      if(differenceDays < currentInstance.tiemposAtencionUrgentes[0])
        return false;
    }
  }
  return true;
}
bool disponibilityMed(instanceStruct currentInstance,int i_m,int i_d,int i_b){
  //CHEQUEAR SI EL BLOQUE ES DE LA MAÑANA O DE LA TARDE, para esto tomamos el total de bloques y la primera mitad es mañana
  //y la segundad mitad es de tarde
  int turno; //1 -> mañana, 2 -> tarde
  if(i_b < (currentInstance.nBloques / currentInstance.turnosPorDia))
    turno = 1;
  else
    turno = 2;
  //CHEQUEAR disponibilidad del medico
  if(stoi(currentInstance.horarioDoctores[i_m][i_d]) == 3)
    return true;
  if(stoi(currentInstance.horarioDoctores[i_m][i_d]) == 0)
    return false;
  if(stoi(currentInstance.horarioDoctores[i_m][i_d]) == turno)
    return true;

  return false;
}
void assignToPatient(int tipoPaciente,int i_p,int i_d,int i_b,int i_m){
  solutionMedicoStruct solution;
  solution.paciente = i_p;
  solution.tipoPaciente = tipoPaciente;
  solution.dia = i_d;
  solution.bloque = i_b;
  solution.medico = i_m;
  asignacion.push_back(solution);
}
