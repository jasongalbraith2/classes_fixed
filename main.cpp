#include <iostream>
#include <cstring>
#include <vector>
#include <limits>

#include "digitalmedia.h"
#include "movie.h"
#include "music.h"
#include "videogame.h"

bool check_for_fail() {
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
  }
  return false;
}

void media_add(std::vector<DigitalMedia*>& mediaVector) {
  /* First, ask for which type of media,
     then get the global variables for
     the main function, then cipher into
     sub-functions */
  const unsigned int ADD_BUFFER = 20;
  char addCommand[ADD_BUFFER];
  
  std::cout << "[MEDIA TYPE? (MUSIC, MOVIE, VIDEOGAME) >> ";
  std::cin.getline(add_command, ADD_BUFFER);

  if (check_for_fail()) {
    std::cout << "Failed input. Returning to main loop.\n";
    return;
  }
  
  if (strcmp("MUSIC", add_command) == 0) {
    return;
  }
  else if (strcmp("MOVIE", add_command) == 0) {
    return;
  }
  else if (strcmp("VIDEOGAME", add_command) == 0) {
    return;
  }
  else {
    return;
  }
   
  /* DigitalMedia* funny = new Music(args...); medias.push_back(funny); */
}
	
int main()
{
  /* Overarching variables */
  std::vector<DigitalMedia*> medias;
    
  /* Main loop variables */
  bool running = true;
  bool comp_loop = true;
  const unsigned int COMMAND_BUFFER = 6;
  char command[COMMAND_BUFFER];
    
  while (running) {
    /* Grab the given command */
    std::cout << "[COMMAND] >> ";
    std::cin.getline(command, COMMAND_BUFFER);

    /* Check for a fail of the getline,
       ESPECIALLY IF PAST THE BUFFER. */
    if (check_for_fail()) comp_loop = false;

    if (comp_loop) {
      /* Add method */
      if (strcmp(command, "ADD") == 0) {
        media_add(medias);
      }
        
      /* Search method */
      else if (strcmp(command, "SEARCH") == 0) {
	continue;
      }
        
      /* Delete method*/
      else if (strcmp(command, "DELETE") == 0) {
	continue;
      }
        
      /* Quit method */
      else if (strcmp(command, "QUIT") == 0) {
	running = false;
      }
        
      /* No valid command was inputted */
      else {
	continue;
      }
    }
  }

  for (DigitalMedia* p : medias) {
    delete p;
  }
    
  return 0;
}
