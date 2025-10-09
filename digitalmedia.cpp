#include "digitalmedia.h"
#include <cstring>

int DigitalMedia::getYear() const {
  return year;
}

char* DigitalMedia::getTitle() const {
  return title;
}

DigitalMedia::DigitalMedia(char* _title, unsigned int _year) {
  size_t len = std::strlen(_title);
  title = new char [len + 1];
  std::strcpy(title, _title);

  year = _year;
}

DigitalMedia::~DigitalMedia() {
  delete[] title;
}
