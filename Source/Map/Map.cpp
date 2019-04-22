#include "Map.h"

using namespace std;



Map::Map(/* args */)
{
    // nothing to do in the constructor
    isMapInit = false;
    IsOtherPlayerPositionUpdate = false;
    IsRoadMapUpdate = false;
    NbOfTurnLeft = 0;
    ActualChefPosition.posX = 0;
    ActualChefPosition.posY = 0;
}

  void Map::setMap(string * LinePointeur){
    // Execute for each line
    for(int i = 0; i < MAP_LENGTH; i++){
        LinePointeur[i].copy(kitchen[i],MAP_WIDTH);
    }
    isMapInit = true;
}

int Map::UpdateMap(int Posx, int Posy){

    // check wether the map has already been update
    if(isMapInit){
        // remove the old chef position 
        kitchen[ActualChefPosition.posX][ActualChefPosition.posY] = FreePlaceA_MapObject;
        
        ActualChefPosition.posX = Posx;
        ActualChefPosition.posY = Posy;

        // set the new chef position
        kitchen[Posx][Posy] = MyChef_MapObject;

    }
}



#if defined DEBUG

void Map::PrintMap(){

for(int j =0 ; i< MAP_WIDTH; j++ ){}
    for(int i=0; i < MAP_LENGTH; i++ ){
        cout << kitchen[j][i];
    }
}
}

#endif

