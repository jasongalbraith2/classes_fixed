#include <iostream>
#include <cstring>
#include <vector>

int main()
{
    std::vector<DigitalMedia> medias;
    
    /* Main loop variables */
    bool running = true;
    const unsigned int COMMAND_BUFFER = 6;
    char command[6];
    
    
    while (running) {
        std::cout << "[COMMAND] >> ";
        std::cin.getline(command, COMMAND_BUFFER);
        
        /* Add method */
        if (strcmp(command, "ADD")) {
            continue;
        }
        
        /* Search method */
        else if (strcmp(command, "SEARCH")) {
            continue;
        }
        
        /* Delete method*/
        else if (strcmp(command, "DELETE")) {
            continue;
        }
        
        /* Quit method */
        else if (strcmp(command, "QUIT")) {
            running = false;
        }
        
        /* No valid command was inputted */
        else {
            continue;
        }
    }
    
    return 0;
}
