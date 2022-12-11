#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H
#include <player.h>

class environnement
{
    public:
        environnement();
        virtual ~environnement();
        void gestionEnv(RenderWindow&,sol&);

        sf::Texture tx_env;
        sf::Sprite sp_env;
        vector<sf::Sprite> vec_env;

    protected:

    private:
};

#endif // ENVIRONNEMENT_H
