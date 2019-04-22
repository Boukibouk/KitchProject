#ifndef TCASE_H
#define TCASE_H

#include <iostream>
#include <fstream>
/* 
* Further include can be added 
*
*/

/*Define all the log needed */
#define LogInfo(x) std::cout << "*** INFO : "#x << std::endl; 
#define LogError(x) std::cout << "*** ERROR : "#x << std::endl;

/* Not needed for the momemnt */
/*
class TCASE
{
private:

public:
     virtual void init(){};
     virtual void Run(){};
     virtual void End(){};
};
*/

#endif