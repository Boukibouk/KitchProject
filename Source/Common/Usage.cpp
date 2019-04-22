#include "ObjectDefinition.h"

using namespace std;


/******Map Element class definition ****/
 MapElement::MapElement(){

}



void CopyDataToMap(char * src, char* dest){
    for(int i=0; i < MAP_WIDTH; i++)
    src[i] = dest[i];
}

