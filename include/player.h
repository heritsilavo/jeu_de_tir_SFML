#ifndef PLAYER_H
#define PLAYER_H
#include <sol.h>
#include <SFML/System.hpp>
#define player_heigth 47
#define player_width 21

enum dir{l,r};

class player
{
    public:
        player();
        virtual ~player();
        void getionPlayer(RenderWindow&,sol&);

        sf::Sprite players;
        sf::Texture player_tx;
        sf::Clock cl_desc;
        sf::Clock cl_saut;
        sf::Clock cl_max_saut;
        int speed;
        int cur_sol;
        int nb_saut;
        bool gravite;
        dir player_direction;
    protected:

    private:
};

#endif // PLAYER_H
