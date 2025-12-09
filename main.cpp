#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <iomanip>

#include "digitalmedia.h"
#include "movie.h"
#include "music.h"
#include "videogame.h"

void media_add(std::vector<DigitalMedia*>& mediaVector) {
	char addCommand[10];
	char title[100];
	int year;
	
	std::cout << "[MEDIA TYPE? (MUSIC, MOVIE, VIDEOGAME) >> ";
	std::cin >> std::setw(10) >> addCommand;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // GPT PROMPT: "HOW TO READ FOR SPACED INPUT"
	
	std::cout << "Title of media >> ";
	std::cin.getline(title, 100); // GPT PROMPT: "HOW TO READ FOR SPACED INPUT"
	
	std::cout << "Year of creation >> ";
	std::cin >> year;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // GPT PROMPT: "HOW TO READ FOR SPACED INPUT"
	
	if (strcmp("MUSIC", addCommand) == 0) {
		char publisher[100];
		char artist[100];
		double duration;
		
		std::cout << "Publisher name >> ";
		std::cin.getline(publisher, 100); // GPT PROMPT: "HOW TO READ FOR SPACED INPUT"
		
		std::cout << "Artist name >> ";
		std::cin.getline(artist, 100); // GPT PROMPT: "HOW TO READ FOR SPACED INPUT"
		
		std::cout << "Duration >> ";
		std::cin >> duration;
		
		DigitalMedia* newMusic = new Music(title, year, publisher, artist, duration);
		mediaVector.push_back(newMusic);
	}
	else if (strcmp("MOVIE", addCommand) == 0) {
		char director[100];
		double duration;
		
		std::cout << "Director name >> ";
		std::cin.getline(director, 100); // GPT PROMPT: "HOW TO READ FOR SPACED INPUT"
		
		std::cout << "Duration >> ";
		std::cin >> duration;
		
		DigitalMedia* newMovie = new Movie(title, year, director, duration);
		mediaVector.push_back(newMovie);
	}
	else if (strcmp("VIDEOGAME", addCommand) == 0) {
		char publisher[100];
		double rating;
		
		std::cout << "Publisher name >> ";
		std::cin.getline(publisher, 100); // GPT PROMPT: "HOW TO READ FOR SPACED INPUT"
		
		std::cout << "Rating >> ";
		std::cin >> rating;
		
		DigitalMedia* newVideoGame = new VideoGame(title, year, publisher, rating);
		mediaVector.push_back(newVideoGame);
	}
}

void search_media(std::vector<DigitalMedia*>& mediaVector, bool deleteMedias) {
	char temp[6];
	
	std::vector<int> indices;
	int counter = 0;
	int UIcounter = 1;
	
	std::cout << "Search by title or year >> ";
	std::cin >> std::setw(6) >> temp;
	
	if (strcmp(temp, "TITLE") == 0) {
		char title[100];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // GPT PROMPT: "HOW TO READ FOR SPACED INPUT"
		
		std::cout << "Title >> ";
		std::cin.getline(title, 100); // GPT PROMPT: "HOW TO READ FOR SPACED INPUT"
		
		for (DigitalMedia* media : mediaVector) {
			if (strcmp(title, media->getTitle()) == 0) {
				std::cout << UIcounter << "--- MEDIA: "
				<< media->getTitle()
				<< " || YEAR: " << media->getYear() << '\n';
				
				indices.push_back(counter);
				++UIcounter;
			}
			++counter;
		}
	}
	else if (strcmp(temp, "YEAR") == 0) {
		int year;
		std::cout << "Year >> ";
		std::cin >> year;
		
		for (DigitalMedia* media : mediaVector) {
			if (year == media->getYear()) {
				std::cout << UIcounter << "--- MEDIA: "
				<< media->getTitle()
				<< " || YEAR: " << media->getYear() << '\n';
				
				indices.push_back(counter);
				++UIcounter;
			}
			++counter;
		}
	}
	
	if (deleteMedias && !indices.empty()) {
		int deleteIndex;
		std::cout << "Enter a number to delete >> ";
		std::cin >> deleteIndex;
		--deleteIndex;
		
		if (deleteIndex >= 0 && deleteIndex < (int)indices.size()) {
			int realIndex = indices[deleteIndex];
			delete mediaVector[realIndex];
			mediaVector.erase(mediaVector.begin() + realIndex);
		}
	}
}

int main() {
	std::vector<DigitalMedia*> medias;
	
	bool running = true;
	const unsigned int COMMAND_BUFFER = 7;
	char command[COMMAND_BUFFER];
	
	while (running) {
		std::cout << "[COMMAND] >> ";
		std::cin >> std::setw(COMMAND_BUFFER) >> command; // GPT PROMPT: "HOW TO READ FOR SPACED INPUT"
		
		if (strcmp(command, "ADD") == 0) {
			media_add(medias);
		}
		else if (strcmp(command, "SEARCH") == 0) {
			search_media(medias, false);
		}
		else if (strcmp(command, "DELETE") == 0) {
			search_media(medias, true);
		}
		else if (strcmp(command, "QUIT") == 0) {
			running = false;
		}
	}
	
	for (DigitalMedia* p : medias) {
		delete p;
	}
	medias.clear();
	
	return 0;
}
