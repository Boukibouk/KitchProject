#include "TCASE1.h"

using namespace std;

void RunTcase1(){
  
  LogInfo("Run the Test TCASE 1 : Read the Map from txt file  and set it to the Map Class ");

  Map MyMap;  
  string line[11];
  string MapName;
  ifstream MapFileTxt;
  MapFileTxt.open("Test/Source/TestCase/TCASE1/MapToLoad.txt");
  
  if (MapFileTxt.is_open())
  {
      LogInfo("File MapToLoad.txt open with success");
      getline(MapFileTxt,MapName);

      for(int i= 0; i< MAP_LENGTH; i++){
          getline(MapFileTxt,line[i]);
          std::cout<< line[i]<< endl;      
      }

      MyMap.setMap(line);

  
    MapFileTxt.close();
  }
  else{
      LogError("Cannot open MapToLoad.txt");
  }
 


    

}
