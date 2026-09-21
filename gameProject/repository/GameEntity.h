#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <iostream>


using namespace std;

typedef enum{
    BACKLOG,
    IN_PROGRESS,
    COMPLETED
} gameStatus_t;

typedef enum{
    DIGITIAL,
    HARDCOPY

} medium_type_t;


class GameEntity {
private:
    int id;
    string title;
    int releaseYear;
    string genre;
	gameStatus_t status;
    medium_type_t medium_type;
	int fileSizeGB;
	string drmPlataform;
	bool hasBox;
	string region;
public:
    
    int getId() const { return id; }
    void setId(int value) { id = value; }

    string getTitle() const { return title; }
    void setTitle(const string& value) { title = value; }

    int getReleaseYear() const { return releaseYear; }
    void setReleaseYear(int value) { releaseYear = value; }

    string getGenre() const { return genre; }
    void setGenre(const string& value) { genre = value; }

    gameStatus_t getStatus() const { return status; }

	string getStatusString() {
		switch (this->status)
		{
		case gameStatus_t::BACKLOG:
			return "BACKLOG";
		case gameStatus_t::IN_PROGRESS:
			return "IN_PROGRESS";
		case gameStatus_t::COMPLETED:
			return "COMPLETED";
		default:
			return "";
		}
	}

    string getMediumTypeSting() {
		switch (this->medium_type)
		{
		case medium_type_t::DIGITIAL:
			return "DIGITIAL";
		case medium_type_t::HARDCOPY:
			return "HARDCOPY";
		default:
			return "";
		}
	}

    void setStatus(gameStatus_t value) { status = value; }

    medium_type_t getMediumType() const { return medium_type; }
    void setMediumType(medium_type_t value) { medium_type = value; }

    int getFileSizeGB() const { return fileSizeGB; }
    void setFileSizeGB(int value) { fileSizeGB = value; }

    string getDrmPlataform() const { return drmPlataform; }
    void setDrmPlataform(const string& value) { drmPlataform = value; }

    bool getHasBox() const { return hasBox; }
    void setHasBox(bool value) { hasBox = value; }

    string getRegion() const { return region; }
    void setRegion(const string& value) { region = value; }
};
#endif 