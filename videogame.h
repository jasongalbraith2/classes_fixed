#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <cstring>
#include "digitalmedia.h"

class VideoGame : public DigitalMedia {

private:
  char* publisher;
  double rating;

public:
  char* getPublisher() const;
  double getRating() const;

  VideoGame(char* _title, unsigned int _year, char* _publisher, double _rating);
  virtual ~VideoGame();
};

#endif
