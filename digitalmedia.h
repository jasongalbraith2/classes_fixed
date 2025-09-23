class DigitalMedia {

private:
    char* title;
    int year;
    
public:
    /* Main class functions */
    const int* getYear() { return year; }
    const char* getTitle() { return title; }
    
    /* Subclass functions */
    virtual const char* getPublisher() = 0;
    virtual const char* getArtist() = 0;
    virtual const char* getDirector() = 0;
    virtual double getDuration() = 0;
    virtual double getRating() = 0;
    
    DigitalMedia(const char* _title, const unsigned int _year) {
        title = new char[strlen(_title) + 1];
        strcpy(title, _title);
        
        year = _year;
    }
    ~DigitalMedia() {
        delete[] title;
        delete year;
    }
};
