#include "lib/sqlite3.h"
#include <iostream>
#include "repository/GameEntity.h"
#include "repository/dao/GameDAO.h"



int main(){
	GameEntity* game = new GameEntity();
	game->setTitle("HitMan 47");
	game->setReleaseYear(2017);
	game->setGenre("Stealth");
	game->setStatus(gameStatus_t::COMPLETED);
	game->setMediumType(medium_type_t::DIGITIAL);
	game->setFileSizeGB(81);
	game->setHasBox(false);
	game->setRegion("USA");

	GameDAO gameDao("game.db");
	gameDao.createGame(*game);

	
}