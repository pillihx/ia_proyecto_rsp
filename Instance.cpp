#include "Instance.hpp"

vector<string> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

instanceStruct readInstance(string pathInstance){
  instanceStruct newInstance;
	string lineCurrent;
	int counterLine = 0,i,day;

	ifstream infile;
	infile.open (pathInstance,ios::out);
  while(!infile.eof()){
		vector<string> arr; //array for split
    getline(infile,lineCurrent); // Saves the line in STRING.
    //cout << lineCurrent;
		arr=split(lineCurrent," "); //execute split
    if(counterLine == 0){//first line
			newInstance.nMaquinas = stoi(arr[0]);
			newInstance.nDoctores = stoi(arr[1]);
			newInstance.nPacientes = stoi(arr[2]);
		}
		else if(counterLine > 0 && counterLine < (newInstance.nDoctores + 1)){//lines from 1 to n-1
      int arr_size = arr.size();
      for(int day=0; day<4; day++){//4 semanas
        arr.push_back("0");//Sabado
        arr.push_back("0");//Domingo
        for(int i=0; i<arr_size;i++){
          arr.push_back(arr[i]);
        }
      }
      newInstance.horarioDoctores.push_back(arr);
		}
		else if(counterLine == newInstance.nDoctores + 1){//last line
      newInstance.NpacR = stoi(arr[0]);
			newInstance.NpacP = stoi(arr[1]);
			newInstance.NpacU = stoi(arr[2]);
		}
		counterLine++;
  }
  //fill anothers days with weekends

  //close file
	infile.close();

  return newInstance;
}
