#ifndef GAMEDAO_H
#define GAMEDAO_H

#include "DAO.h"
#include "../GameEntity.h"

class GameDAO : public DAO {
private:

public:
	GameDAO(char * databaseName) : DAO(databaseName) {}
	
	int createGame(GameEntity gameEntity);
};

#endif
