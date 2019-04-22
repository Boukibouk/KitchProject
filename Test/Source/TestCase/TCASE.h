#ifndef TCASE_H
#define TCASE_H


class TCASE
{
private:

public:
     virtual void init(){/* Abstract */ };
     virtual void Run(){ /* Abstract */};
     virtual void End(){ }/* Abstract */;
};


#endif