#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

#include <cstring>

class DigitalMedia {

protected:
    char* title;
    unsigned int year;
    
public:
  /* Main class functions */
  int getYear() const;
  char* getTitle() const;

  DigitalMedia(const char* _title, const unsigned int _year);
  virtual ~DigitalMedia();
};

#endif
