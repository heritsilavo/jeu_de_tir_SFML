#include "environnement.h"
#include <math.h>

environnement::environnement()
{
    tx_env.loadFromFile("bg.png");
    sp_env.setTexture(tx_env);
}

void environnement::gestionEnv(RenderWindow &win,sol& ma_sol){
    int compte=ceil((double)ma_sol.piste/win_w);
    for(int i(0);i<compte;i++){
        vec_env.push_back(sp_env);
        vec_env[i].setPosition(sf::Vector2f(i*win_w-10,0));
        win.draw(vec_env[i]);
    }
}

environnement::~environnement()
{
    //dtor
}
