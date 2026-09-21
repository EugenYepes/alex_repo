#ifndef REVIEWENTITY_H
#define REVIEWENTITY_H

#include <iostream>

using namespace std;


class ReviewEntity {
private:
   int id;
   int score;
   string summaryText;
   string reviewDate;
public:

   int getId() const { return id; }
   void setId(int value) { id = value; }

   int getScore() const { return score; }
   void setScore(int value) { score = value; }

   string getSummaryText() const { return summaryText; }
   void setSummaryText(const string& value) { summaryText = value; }

   string getReviewDate() const { return reviewDate; }
   void setReviewDate(const string& value) { reviewDate = value; }
};

#endif