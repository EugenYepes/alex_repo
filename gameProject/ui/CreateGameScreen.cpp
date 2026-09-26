#include "CreateGameScreen.h"

/*

// int getId() const { return id; }
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
			return "backlog";
		case gameStatus_t::IN_PROGRESS:
			return "in_progress";
		case gameStatus_t::COMPLETED:
			return "completed";
		default:
			return "";
		}
	}

    string getMediumTypeSting() {
		switch (this->medium_type)
		{
		case medium_type_t::DIGITIAL:
			return "digital";
		case medium_type_t::HARDCOPY:
			return "hardcopy";
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

*/

GameEntity CreateGameScreen::display() {
	GameEntity game;
    std::cout << "Please give a title: ";
    string title_input;
    std::cin >> title_input;
    game.setTitle(title_input);

    std::cout << "Please give a release year: ";
    int releaseYear_input;
    std::cin >> releaseYear_input;
    game.setReleaseYear(releaseYear_input);


    std::cout << "Please give a genre: ";
    string genre_input;
    std::cin >> genre_input;
    game.setGenre(genre_input);

    std::cout << "Please give a status [1 - Backlog, 2 - In-progress, 3 - Completed]: ";
    int status_input;
    std::cin >> status_input;
	switch (status_input)
	{
	case 1:
		game.setStatus(gameStatus_t::BACKLOG);
	case 2:
		game.setStatus(gameStatus_t::IN_PROGRESS);
	case 3:
		game.setStatus(gameStatus_t::COMPLETED);
    default:
        game.setStatus(gameStatus_t::BACKLOG);
	}
    

	std::cout << "Please give a status [1 - Digital, 2 - HardCopy: ";
    int media_input;
    std::cin >> media_input;
	switch (media_input)
	{
	case 1:
		game.setMediumType(medium_type_t::DIGITIAL);
	case 2:
		game.setMediumType(medium_type_t::HARDCOPY);
    default:
		game.setMediumType(medium_type_t::DIGITIAL);
	}
    
    std::cout << "Please give a file size(GB): ";
    int fileSize_input;
    std::cin >> fileSize_input;
    game.setFileSizeGB(fileSize_input);


	std::cout << "Pelase enter the Region: ";
	string drmPlat_input;
	std::cin >> drmPlat_input;
	game.setRegion(drmPlat_input);

	std::cout << "Pelase enter the has box: ";
	bool hasBox_input;
	std::cin >> hasBox_input;
	game.setHasBox(hasBox_input);

	std::cout << "Pelase enter the Region: ";
	string region_input;
	std::cin >> region_input;
	game.setRegion(region_input);

	return game;
}


