#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

#include <cstring>

class DigitalMedia {

protected:
  char* title;
  unsigned int year;
    
public:
  int getYear() const;
  char* getTitle() const;

  DigitalMedia(char* _title, unsigned int _year);
  virtual ~DigitalMedia();
};

#endif
