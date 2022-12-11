#include <SFML/Graphics.hpp>
#include <environnement.h>
//#include <player.h> -------------->dans environnement.h
//#include <sol.h>   --------------->dans player.h
//#define win_w 1370 --------------->dans sol.h
//#define win_h 700  --------------->dans sol.h

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(win_w, win_h), "SFML window",sf::Style::Close);
    window.setPosition(sf::Vector2i(0,0));
    sol masol;
    player maplayer;
    environnement env;
	// Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();
        //sol
        masol.gestionSol(window,"sol.png");
        //player
        maplayer.getionPlayer(window,masol);
        //environement
        env.gestionEnv(window,masol);
         //sol
         masol.gestionSol(window,"sol.png");
        //player
        maplayer.getionPlayer(window,masol);
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
