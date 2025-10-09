#include "digitalmedia.h"
#include "movie.h"
#include <cstring>

char* Movie::getDirector() const {
  return director;
}

double Movie::getDuration() const {
  return duration;
}

Movie::Movie(char* _title, unsigned int _year, char* _director, double _duration)
  : DigitalMedia(_title, _year) {
  size_t len = std::strlen(_director);
  director = new char [len + 1];
  std::strcpy(director, _director);

  duration = _duration;
}

Movie::~Movie() {
  delete[] director;
}
