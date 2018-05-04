#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Game.h"

#define NOINTRO 1

void Game::Start()
{
    if (NOINTRO)
        MainMenu();
    StarWarsIntro();
}

void Game::StarWarsIntro()
{
    system("cls");
    std::cout << "\t\tA long time ago, in a galaxy far, far away.........";
    Sleep(1000);
    for (int m = 12; m >= 0; m--) {
        system("cls");
        for (int k = m; k >= 0; --k){
            std::cout << '\n';
        }
        std::cout << "\t\tTurmoil has engulfed the\n\t\tGalactic Republic. The taxation"
                    "\n\t\tof trade routes to outlying star\n\t\tsystems is in dispute."
                    "\n\n\t\tHoping to resolve the matter\n\t\twith a blockade of deadly"
                    "\n\t\tbattleships, the greedy Trade\n\t\tFederation has stopped all"
                    "\n\t\tshipping to the small planet\n\t\tof Naboo."
                    "\n\n\t\tWhile the Congress of the\n\t\tRepublic endlessly debates"
                    "\n\t\tthis alarming chain of events,\n\t\tthe Supreme Chancellor has"
                    "\n\t\tsecretly dispatched two Jedi\n\t\tKnights, the guardians of"
                    "\n\t\tpeace and justice in the\n\t\tgalaxy, to settle the conflict....";

        Sleep(700);
    }
    Sleep(1000);
    system("cls");
    MainMenu();
}
void Game::MainMenu()
{
    system("cls");
    if (state == PAUSE){
    std::cout << "\t\tWelcome in the far, far In-game Menu!!!"
                "\n\t1. Continue the conquest of the Galactic"
                "\n\t2. StarWarsIntro"
                "\n\t3. Leave the battleship"
                "\n\t4. Restart";
    } else {
    std::cout << "\t\tWelcome in the far, far Main Menu!!!"
                "\n\t1. Deep into the Galactic"
                "\n\t2. Intro"
                "\n\t3. Leave the battleship";
            }
    while (true){
        char ch = _getch();
        switch(ch){
            case '1':   _map_.SwapMap();
                        state = INGAME;
                        _map_.DrawMap(); 
                        getDirection(); break;
            case '2':   StarWarsIntro(); break;
            case '3':   exit(0);
            case char(27): if (state == PAUSE) {MainMenu();state = INGAME;}
            default:    if (state == PAUSE)
                            if (ch == '4') {
                                Restart();
                                state = INGAME;
                                _map_.DrawMap();
                                getDirection();
                            }
        }
    }
}

void Game::getDirection()
{
    while (state == INGAME)
    {
        char ch = _getch();
        if (ch == 'w' || ch == 'w'){
            if (_map_.Map[player->getX()-1][player->getY()] == 32){
                _map_.Map[player->getX()][player->getY()] = 32;
                player->setX(player->getX() - 1);
                _map_.DrawMap();
            }
        }
        if (ch == 'a' || ch == 'A'){
            if (_map_.Map[player->getX()][player->getY()-1] == 32){
                _map_.Map[player->getX()][player->getY()] = 32;
                player->setY(player->getY() - 1);
                _map_.DrawMap();
            }
        }
        if (ch == 's' || ch == 'S'){
            if (_map_.Map[player->getX()+1][player->getY()] == 32){
                _map_.Map[player->getX()][player->getY()] = 32;
                player->setX(player->getX() + 1);
                _map_.DrawMap();
            }
        }
        if (ch == 'd' || ch == 'D'){
            if (_map_.Map[player->getX()][player->getY()+1] == 32){
                _map_.Map[player->getX()][player->getY()] = 32;
                player->setY(player->getY() + 1);
                _map_.DrawMap();
            }
        }
        if (ch == ' '){
            shot();
            _map_.DrawMap();
        }
        if (ch == char(27)){
            Pause();
        }
    }
}

void Game::shot(){
    player->bull.push_back(new Bullet(player->getX(), player->getY()+1));
}

void Game::Pause()
{
    state = PAUSE;
    MainMenu();
}

void Game::Restart(){
    player->resetXY();
    _map_.SwapMap();
    for (Bullet* obj:player->bull) {
        _map_.Map[obj->getX()][obj->getY()] = 32;
        delete obj;
    }
    player->bull.clear();
}
