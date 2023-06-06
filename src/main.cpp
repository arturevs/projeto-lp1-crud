/**
 * @file main.cpp
 * @brief Arquivo principal do programa.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"
#include "menu.hpp"

/**
 * @brief Setup inicial do programa, que adiciona exemplos de
 * músicas e playlists para demonstrar as funcionalidades do
 * programa.
 * 
 * @param songs Lista encadeada (LinkedList) de músicas (Song) do sistema.
 * @param playlists Lista encadeada (LinkedList) de playlists (Playlist) do sistema.
 */
void setup(LinkedList<Song> &songs, LinkedList<Playlist> &playlists){
    int choice;
    std::fstream arquivo;
    arquivo.open("input.txt", std::ios::in);
    std::string linha;

    std::cout << "Deseja executar o setup inicial? Isso irá adicionar\n" <<
                 "alguns exemplos de músicas e playlists\n";
    std::cout << "1. Sim\n";
    std::cout << "0. Não\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    if(choice == 0) return;

    while(getline(arquivo, linha)){
        std::string palavra = "";
        std::string autor = "";
        std::string play = "";
        Playlist *x;

        for(auto c: linha){
            if(c == ';'){
                Playlist pl(palavra);
                playlists.add(pl);
                x = playlists.searchValue(pl);
                play = palavra;
                palavra = "";
                continue;
            }
            else if(c == ':'){
                autor = palavra;
                palavra = "";
                continue;
            }
            else if(c == ',' || c == '.'){
                Song mus(autor, palavra);
                songs.add(mus);
                x->addSong(mus);
    
                autor = "";
                palavra = "";
                continue;
            }
            palavra += c;
        }
        
    }

    std::cout << "Setup completo\n";
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
}


int main(int argc, char *argv[]){
    LinkedList<Playlist> playlists;
    LinkedList<Song> songs;

    
    setup(songs, playlists);

    int exit{0};

    while(exit == 0){
        exit = mainMenu(songs, playlists);
    }

    playlists.clear();
    songs.clear();

    return 0;
}