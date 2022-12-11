#ifndef SOL_H
#define SOL_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include <vector>
#include <ctime>

#define sol_heigth 105
#define sol_width 450
#define sol_scale 0.4
#define win_w 1365
#define win_h 700
using namespace sf;
using namespace std;

class sol
{
    public:
        sol();
        virtual ~sol();
        void gestionSol(RenderWindow&,string);
        sf::Sprite sol_sp;
        int sol_pos;
        vector<sf::Sprite> sols;
        int piste;
        bool pushed;
    protected:

    private:
};

#endif // SOL_H
