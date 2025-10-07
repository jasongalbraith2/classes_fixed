#ifndef MUSIC_H
#define MUSIC_H

#include "digitalmedia.h"

class Music : public DigitalMedia {

private:
  char* publisher;
  char* artist;
  double duration;

public:
  char* getPublisher() const;
  char* getArtist() const;
  double getDuration() const;
  
  Music(char* _title, unsigned int _year, char* _publisher, char* _artist, double _duration);
  ~Music();
};

#endif
