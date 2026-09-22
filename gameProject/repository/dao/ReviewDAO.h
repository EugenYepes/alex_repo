#ifndef REVIEWDAO_H
#define REVIEWDAO_H

#include "DAO.h"
#include "../ReviewEntity.h"

class ReviewDAO : public DAO {
private:

public:
	ReviewDAO(char * databaseName) : DAO(databaseName) {}
	
	int createReview(ReviewEntity gameEntity);
};

#endif
