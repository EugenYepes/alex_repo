#ifndef MAINMANUSCREEN_H
#define MAINMANUSCREEN_H

#include <iostream>
#include "repository/AccountEntity.h"
#include "Screen.h"

class CreateAccountScreen : public Screen<AccountEntity>
{
private:
    
public:
    AccountEntity display() override;
};



#endif 