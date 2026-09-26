#include <iostream>
#include "repository/GameEntity.h"
#include "repository/AccountEntity.h"
#include "repository/dao/GameDAO.h"
#include "repository/dao/AccountDAO.h"


int main(){
	std::cout<<"hello"<< std::endl;
	GameEntity* game = new GameEntity();
	game->setTitle("HitMan 47");
	game->setReleaseYear(2017);
	game->setGenre("Stealth");
	game->setStatus(gameStatus_t::COMPLETED);
	game->setMediumType(medium_type_t::DIGITIAL);
	game->setFileSizeGB(81);
	game->setHasBox(false);
	game->setRegion("USA");

	GameDAO gameDao("C:/Users/eugen/Desktop/Classes/Preply/Alex/Project/gameProject/game.db");
	gameDao.createGame(*game);

	AccountEntity* account = new AccountEntity();
	account->setEmail("alex@gmail.com");
	account->setUserName("alex1234");
	account->setPrefPlatform("Steam");
	account->setOutletName("blabla");
	account->setAccountType(accountType_t::PLAYER);

	AccountDAO accountDao("C:/Users/eugen/Desktop/Classes/Preply/Alex/Project/gameProject/game.db");
	accountDao.createAccount(*account);
}