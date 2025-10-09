#include "digitalmedia.h"
#include "videogame.h"
#include <cstring>

char* VideoGame::getPublisher() const {
  return publisher;
}

double VideoGame::getRating() const {
  return rating;
}

VideoGame::VideoGame(char* _title, unsigned int _year, char* _publisher, double _rating)
  : DigitalMedia(_title, _year) {
  size_t len = std:;strlen(_publisher);
  publisher = new char [len + 1];
  std::strcpy(publisher, _publisher);

  rating = _rating;
}

~VideoGame::VideoGame() {
  delete[] publisher;
}
