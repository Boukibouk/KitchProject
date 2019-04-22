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

    ActualOpponentChefPosition.posX = 0;
    ActualOpponentChefPosition.posY = 0;
}

  void Map::setMap(string * LinePointeur){
    // Execute for each line
    for(int i = 0; i < MAP_LENGTH; i++){
        LinePointeur[i].copy(kitchen[i],MAP_WIDTH);
    }
    isMapInit = true;
#if defined DEBUG
   Map::PrintMap();
#endif 
}

bool Map::UpdateMap(int PosChefx, int PosChefy, int PosOpponentChefx, int PosOpponentChefy ){
    bool retval = false;

    // check wether the map has already been update
    if(isMapInit){

        if(PosChefx != NO_POSITION && PosChefy != NO_POSITION ){
        // remove the old chef position 
        kitchen[ActualChefPosition.posX][ActualChefPosition.posY] = FreePlaceA_MapObject;
        
        ActualChefPosition.posX = PosChefx;
        ActualChefPosition.posY = PosChefy;

        // set the new chef position
        kitchen[PosChefx][PosChefy] = MyChef_MapObject;
        }

        if(PosOpponentChefx != NO_POSITION && PosOpponentChefy != NO_POSITION){
        
        // set the old opponen position free
        kitchen[ActualOpponentChefPosition.posX][ActualOpponentChefPosition.posY] = FreePlaceA_MapObject;
        
        ActualOpponentChefPosition.posX = PosOpponentChefx;
        ActualOpponentChefPosition.posY = PosOpponentChefy;

        // set the new opponen position
        kitchen[PosOpponentChefx][PosOpponentChefy] = OpponentChefA_MapObject;

        }
        retval = true;
    }

    return retval;
}

bool Map::UpdateMap(Position NewChefPosition, Position newOpponentPosition)
{
    return UpdateMap(NewChefPosition.posX, NewChefPosition.posY, newOpponentPosition.posX, newOpponentPosition.posY);
}

#if defined DEBUG

 void Map::PrintMap(){

for(int j =0 ; j< MAP_WIDTH; j++ ){
    for(int i=0; i < MAP_LENGTH; i++ ){
        cout << kitchen[j][i];
    }
    cout << '\n';
}
}

#endif

