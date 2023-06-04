/**
 * @file Playlist.hpp
 * @brief Arquivo que contém a classe Playlist.
 */

#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"

/**
 * @brief Classe que implementa uma playlist, contendo uma lista encadeada 
 * (LinkedList) de músicas (Song).
 */
class Playlist{

private:
    std::string name; //!< Nome da playlist.
    LinkedList<Song> songs; //!< Lista de músicas da playlist.

public:
    // Construtor padrão da playlist. 
    Playlist();
    // Construtor da playlist que recebe seu nome. 
    Playlist(std::string name);
    // Destrutor da playlist, que remove todas as músicas. 
    ~Playlist();
    // Retorna o tamanho da playlist.
    size_t getSize();
    // Retorna o nome da playlist. 
    std::string getName();
    // Retorna uma referência para a lista encadeada de músicas. 
    LinkedList<Song> &getSongs();
    // Adiciona uma música à playlist. 
    void addSong(Song song);
    // Remove a música especificada da playlist. 
    void removeSong(Song song);
    // Procura uma música na playlist. 
    Song *searchSong(Song song);
    // Imprime as músicas da playlist. 
    void printSongs();
    // Sobrecarga de operador de igualdade. 
    bool operator==(Playlist &b);
    // Sobrecarga de operador de inserção da playlist. 
    Playlist operator<<(Song &song);
    // Sobrecarga de operador de extração da playlist.
    Playlist operator>>(Song &song);
    // Sobrecarga de operador << ostream.
    friend std::ostream &operator<<(std::ostream &os, Playlist &playlist);
    // Sobrecarga de operador + com playlit de argumento
    Playlist operator+(Playlist &playlist);
    // Sobrecarga de operador + com song de argumento
    Playlist operator+(Song &song);
    // Adiciona músicas de uma playlist à outra.
    void adicionaMusicas(Playlist &playlist);
    // Remove músicas de uma playlist de outra.
    void removeMusicas(Playlist &playlist);
    // Construtor cópia.
    Playlist(const Playlist &playlist);
    // Sobrecarga de operador - com playlist de argumento.
    Playlist operator-(Playlist &playlist);
    // Sobrecarga de operador - com song de argumento.
    Playlist operator-(Song &song);
};

#endif