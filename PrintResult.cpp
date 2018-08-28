#include<iostream>
#include "PrintResult.hpp"

void printResult(instanceStruct currentInstance,vector<solutionMedicoStruct> asignacion,int d_min, int d_max){
  int i_p,i_d,i_b,value;
  printf("|%12s|%100s", "", "Días");
  printf("%s\n", "");
  printf("|%12s", "");
  for(i_d=d_min; i_d < d_max; i_d++)
    printf("|%-47d",i_d+1);

  printf("%s\n", "");
  printf("|%12s", "");
  for(i_d=d_min; i_d < d_max; i_d++){
    for(i_b = 0; i_b < currentInstance.nBloques; i_b++){
      if(i_b < 9)
        printf("|%-1d ",i_b+1);
      else
        printf("|%-2d",i_b+1);
    }
  }
  printf("%s\n", "");

  for(i_p = 0; i_p < currentInstance.nPacientes; i_p++){
    if(i_p < 9)
      printf("|%-10s %d|", "Paciente",i_p + 1);
    else
      printf("|%-9s %d|", "Paciente",i_p + 1);
    for(i_d=d_min; i_d < d_max; i_d++){
      for(i_b = 0; i_b < currentInstance.nBloques; i_b++){
        value = findValue(asignacion,i_p,i_d,i_b)+1;
        if(i_b < 9)
          printf("%-1d |",value);
        else
          printf("%-2d|",value);
      }
    }
    printf("%s\n", "");
  }
  printf("%s\n", "");
  printf("%s\n", "");
}
int findValue(vector<solutionMedicoStruct> asignacion,int i_p,int i_d,int i_b){
  for(int i=0; i<asignacion.size();i++){
    if(asignacion[i].paciente == i_p && asignacion[i].dia == i_d && asignacion[i].bloque == i_b)
      return asignacion[i].medico;
  }
}
