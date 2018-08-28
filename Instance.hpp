#ifndef INSTANCE_H
#define INSTANCE_H

#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>

using namespace std;

struct instanceStruct{
  //parameters
  int tiemposAtencionRadicales[2] = {14,28};//{<tiempo_minimo>,<tiempo_maximo>}
  int tiemposAtencionPaliativos[2] = {2,14};//{<tiempo_minimo>,<tiempo_maximo>}
  int tiemposAtencionUrgentes[2] = {1,2};//{<tiempo_minimo>,<tiempo_maximo>}
  int tiempoTratamiento = 30;//tiempo en minutos
  int tiempoTurno = 4;//tiempo en horas
  int turnosPorDia = 2;//Cantidad de turnos que se llevan a cabo por día
  int nBloques = turnosPorDia * tiempoTurno * 60 / tiempoTratamiento;
  //variables of instance
  int nDias=28; //4 semanas x 5 dias + 3 findesemanas
  int nMaquinas;
  int nDoctores;
  int nPacientes;
  int NpacR;
  int NpacP;
  int NpacU;
  vector<vector<string>> horarioDoctores;
};

vector<string> split(string str,string sep);
instanceStruct readInstance(string pathInstance);

#endif
