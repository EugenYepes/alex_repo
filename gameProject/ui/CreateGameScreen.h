#ifndef CREATEGAMESCREEN_H
#define CREATEGAMESCREEN_H

#include <iostream>
#include "repository/GameEntity.h"
#include "Screen.h"

class CreateGameScreen : public Screen<GameEntity>
{
private:
    
public:

    GameEntity display();
};



#endif 