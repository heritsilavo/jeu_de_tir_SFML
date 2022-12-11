#include "player.h"

player::player()
{
    gravite=true;
    cur_sol=0;
    player_direction=r;
    nb_saut=0;
    speed=1;
    player_tx.loadFromFile("player.png");
    players.setTexture(player_tx);
    players.setPosition(0,win_h-(sol_heigth*sol_scale)-player_heigth);
    cl_desc.restart();
    cl_saut.restart();
    cl_max_saut.restart();
}

void player::getionPlayer(RenderWindow &win,sol& ma_sol){
    //gravite
    if((cl_desc.getElapsedTime().asMilliseconds()>=10)&&gravite){
        players.move(0,2);
        for(size_t i(0);i<ma_sol.sols.size();i++){
            if((players.getPosition().y+player_heigth>=ma_sol.sols[i].getPosition().y)&&
               (players.getPosition().x>=ma_sol.sols[i].getPosition().x)&&
               (players.getPosition().x+1<=ma_sol.sols[i].getPosition().x+(sol_scale*sol_width))
               ){
                players.setPosition(players.getPosition().x,ma_sol.sols[i].getPosition().y-(sol_heigth*sol_scale));
                cur_sol=i;//cout<<cur_sol<<endl;
            }
        }
    }
    //moves
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        player_direction=r;
        players.move(speed,0);
        if(players.getPosition().x>=ma_sol.piste-player_width)players.setPosition(ma_sol.piste-player_width,players.getPosition().y);
        if((players.getGlobalBounds().intersects(ma_sol.sols[cur_sol+1].getGlobalBounds()))&&(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))){
            if(ma_sol.sols[cur_sol+1].getPosition().y<ma_sol.sols[cur_sol].getPosition().y){
                players.setPosition(ma_sol.sols[cur_sol+1].getPosition().x-player_width,ma_sol.sols[cur_sol].getPosition().y-player_heigth);
            }
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        player_direction=l;
        players.move(-speed,0);
        if(players.getPosition().x<=0)players.setPosition(0,players.getPosition().y);
        if((players.getGlobalBounds().intersects(ma_sol.sols[cur_sol-1].getGlobalBounds()))&&(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))){
            if(ma_sol.sols[cur_sol-1].getPosition().y<ma_sol.sols[cur_sol].getPosition().y){
                players.setPosition(ma_sol.sols[cur_sol].getPosition().x,ma_sol.sols[cur_sol].getPosition().y-player_heigth);
            }
        }
    }
    //Run
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))||(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))){
        speed=2;
    }else{
        speed=1;
    }
    //saut
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(cl_saut.getElapsedTime().asMilliseconds()<=150){
            gravite=false;
            if(nb_saut<2){
                (player_direction==r)?players.move(2,-3.5):players.move(-2,-3.5);
            }else if(cl_max_saut.getElapsedTime().asSeconds()>=0.5){
                nb_saut=0;
                cl_max_saut.restart();
            }
        }else{
            gravite=true;
            nb_saut++;
        }
    }else{
        cl_saut.restart();
        gravite=true;
    }
    win.draw(players);
    //Gestion de vue
    if(ma_sol.piste>win_w){
        if(players.getPosition().x<=win_w/2){
            sf::View vue(sf::FloatRect(0,0,win_w,win_h));
            win.setView(vue);
        }else if(players.getPosition().x>=(ma_sol.piste-win_w/2)){
            sf::View vue(sf::FloatRect((ma_sol.piste-win_w),0,win_w,win_h));
            win.setView(vue);
        }else{
            sf::View vue(sf::FloatRect((players.getPosition().x-win_w/2),0,win_w,win_h));
            win.setView(vue);
        }
    }
}

player::~player()
{
    //dtor
}
