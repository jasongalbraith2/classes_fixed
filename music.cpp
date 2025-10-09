#include "digitalmedia.h"
#include "music.h"
#include <cstring>

char* Music::getPublisher() const {
  return publisher;
}

char* Music::getArtist() const {
  return artist;
}

double Music::getDuration() const {
  return duration;
}

Music::Music(char* _title, unsigned int _year, char* _publisher, char* _artist, double _duration)
  : DigitalMedia(_title, _year) {
  size_t len1 = std::strlen(_publisher);
  publisher = new char [len1 + 1];
  std::strcpy(publisher, _publisher);

  size_t len2 = std::strlen(_artist);
  artist = new char [len2 + 1];
  std::strcpy(artist, _artist);

  duration = _duration;
}

Music::~Music() {
  delete[] publisher;
  delete[] artist;
}
