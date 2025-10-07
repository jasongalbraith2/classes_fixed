#include "digitalmedia.h"
#include <cstring>

int DigitalMedia::getYear() const {
  return year;
}

char* DigitalMedia::getTitle() const {
  return title;
}

DigitalMedia::DigitalMedia(const char* _title, const unsigned int _year) {
  size_t len = std::strlen(_title);
  title = new char [len + 1];
  std::strcpy(title, _title);

  year = _year;
}

virtual DigitalMedia::~DigitalMedia() {
  delete title;
}
