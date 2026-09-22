#ifndef ACCOUNTDAO_H
#define ACCOUNTDAO_H

#include "DAO.h"
#include "../AccountEntity.h"

class AccountDAO : public DAO {
private:

public:
	AccountDAO(char * databaseName) : DAO(databaseName) {}
	
	int createAccount(AccountEntity accountEntity);
    
};


#endif
