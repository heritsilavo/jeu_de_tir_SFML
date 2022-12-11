#include "sol.h"

using namespace std;

sol::sol()
{
    piste=0;
    sol_pos=0;
    pushed=false;
}

void sol::gestionSol(RenderWindow &win,string path){
    vector<vector<int>> table({
        {1,0,0},
        {1,0,0},
        {0,1,0},
        {0,0,1},
        {0,0,1},
        {0,1,0},
        {0,0,1},
        {0,0,1},
        {0,0,1},
        {0,1,0},
        {0,1,0},
        {1,0,0},
        {1,0,0},
        {1,0,0},
        {1,0,0}
    });
    sf::Texture tx;
    tx.loadFromFile(path);
    sol_sp.setTexture(tx);
    sol_sp.setScale(sol_scale,sol_scale);
    sol_sp.setTextureRect(sf::IntRect(2050,0,sol_width,sol_heigth));
    if(!pushed){
        for(size_t i(0);i<table.size();i++){
            for(size_t j(0);j<table[i].size();j++){
                if(table[i][j]==1){
                    sols.push_back(sol_sp);
                    piste+=(sol_width*sol_scale);
                    int posY;
                    if(j==0){
                        posY=win_h-sol_heigth;
                    }else if(j==1){
                        posY=win_h-(sol_heigth*1.4);
                    }else if(j==2){
                        posY=win_h-(sol_heigth*1.8);
                    }
                    sols[sols.size()-1].setPosition(sf::Vector2f(sol_pos,posY+70));
                    sol_pos+=(sol_width*sol_scale);
                }
            }
        }
        pushed=true;
    }
    for(size_t i(0);i<sols.size();i++){
        win.draw(sols[i]);
    }
}

sol::~sol()
{
    //dtor
}


