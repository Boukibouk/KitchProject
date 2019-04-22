#ifndef OBJECT_DEF
#define OBJECT_DEF

#include "IncludeGlobal.h"

#define MAP_WIDTH 11
#define MAP_LENGTH 7

enum MapElementDefinition{
 /* Chef */
 MyChef_MapObject = 'z', 
 OpponentChefA_MapObject = 'k', 
 OpponentChefB_MapObject = 'p', 
 
 /* Free place */
 FreePlaceA_MapObject = '.',
 FreePlaceB_MapObject = '1',
 FreePlaceC_MapObject = '0',

 /* Element usage */
 WorkSpace_MapObject = '#',
 DischPlace_MapObject = 'D',
 CustomerWindow_MapObject = 'W',
 
 /* Object for preparation  */
 BlueBerryAlone_MapObject = 'B',
 IceCreamAlone_MapObject = 'I'

};

class MapElement
{
private:
std::map<std::string,char > MapObjectDef;
public:
  MapElement();
  static bool IsFreePlace(MapElementDefinition element);
};



typedef struct PositionStruct
{
int posX;
int posY;
} Position;

void CopyDataToMap(char * src, char* dest);

#endif