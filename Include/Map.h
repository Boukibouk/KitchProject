#ifndef MAP_H
#define MAP_H

#include "ObjectDefinition.h"





class Map
{
private:
    char kitchen[MAP_WIDTH][MAP_LENGTH];
    MapElement Mapobject;
    Position ActualChefPosition;
    bool isMapInit;
    bool IsOtherPlayerPositionUpdate;
    bool IsRoadMapUpdate;

    int NbOfTurnLeft;
    std::vector<Position> RoadMap;



public:
    Map();

     void setMap(std::string *LinePointeur);
     int UpdateMap(int Posx, int Posy);
     int UpdateMap(Position NewPosition);
    
    void CalculateRoadMap(char Destination);
    void UpdateRoadMap();

#if defined DEBUG
     //Only available for Debug propose
     void PrintMap();
#endif 

};



#endif 