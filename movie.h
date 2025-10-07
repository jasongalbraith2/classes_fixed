#ifndef MOVIE_H
#define MOVIE_H

class Movie : public DigitalMedia {

private:
  char* director;
  double duration;

public:
  char* getDirector() const;
  double getDuration() const;
  
  Movie(char* _title, unsigned int _year, char* director, double duration);
  ~Movie();
};

#endif
