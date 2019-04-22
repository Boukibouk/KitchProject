#ifndef MAP_H
#define MAP_H

#include "ObjectDefinition.h"



#define NO_POSITION 0xFF

class Map
{
private:
    char kitchen[MAP_WIDTH][MAP_LENGTH];
    MapElement Mapobject;
    
    Position ActualChefPosition;
    Position ActualOpponentChefPosition;

    bool isMapInit;
    bool IsOtherPlayerPositionUpdate;
    bool IsRoadMapUpdate;

    int NbOfTurnLeft;
    std::vector<Position> RoadMap;



public:
    Map();

     void setMap(std::string *LinePointeur);
     bool UpdateMap(int PosChefx, int PosChefy, int PosOpponentChefx, int PosOpponentChefy );
     bool UpdateMap(Position NewChefPosition, Position newOpponentPosition);
    
    void CalculateRoadMap(char Destination);
    void UpdateRoadMap();

#if defined DEBUG
     //Only available for Debug propose
     void PrintMap();
#endif 

};



#endif 