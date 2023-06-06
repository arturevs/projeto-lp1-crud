/**
 * @file Playlist.cpp
 * @brief Arquivo que implementa os métodos da classe Playlist.
 */

#include <string>
#include <iostream>
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

/**
 * @brief Construtor padrão da playlist.
 */
Playlist::Playlist(){
    this->name = "";
}

/**
 * @brief Construtor da playlist que recebe seu nome.
 * 
 * @param name Nome da playlist.
 */
Playlist::Playlist(std::string name){
    this->name = name;
}

/**
 * @brief Destrutor da playlist, que remove todas as músicas.
 */
Playlist::~Playlist(){
    getSongs().clear();
}

/**
 * @brief Retorna o tamanho da playlist.
 * 
 * @return Número de músicas.
 */
size_t Playlist::getSize(){
    return getSongs().getSize();
}

/**
 * @brief Retorna o nome da playlist.
 * 
 * @return Nome da playlist.
 */
std::string Playlist::getName(){
    return name;
}

/**
 * @brief Retorna uma referência para a lista encadeada de músicas.
 * 
 * @return Referência para a lista de músicas.
 */
LinkedList<Song> &Playlist::getSongs(){
    return songs;
}

/**
 * @brief Adiciona uma música à playlist.
 * 
 * @param song Música a ser adicionada.
 */
void Playlist::addSong(Song song){
    getSongs().add(song);
}

/**
 * @brief Remove a música especificada da playlist.
 * 
 * @param title Título da música.
 */
void Playlist::removeSong(Song song){
    getSongs().removeValue(song);
}

/**
 * @brief Procura uma música na playlist.
 * 
 * @param song Música a ser buscada.
 * @return Retorna o ponteiro para a música, caso ela esteja na lista, ou nullptr
 * caso contrário.
 */
Song *Playlist::searchSong(Song song){
    return getSongs().searchValue(song);
}

/**
 * @brief Imprime as músicas da playlist.
 */
void Playlist::printSongs(){
    getSongs().print();
}

/**
 * @brief Sobrecarga de operador de igualdade.
 * 
 * @return Retorna true se o nome das playlists for igual.
 * @return Retorna false caso contrário.
 */
bool Playlist::operator==(Playlist &b){
    return this->getName() == b.getName();
}

/**
 * @brief Sobrecarga do operador << que adiciona uma música à playlist.
 * 
 * @param song 
 * @return Playlist 
 */

    Playlist* Playlist::operator <<(Song &song)
    {
        if (&song == nullptr)
            return this;
        addSong(song);
        return this;
    }

    Playlist Playlist::operator>>(Song &song)
    {
        // se a a playlist estiver vazia, preenche song com nullptr
        if (songs.getSize() == 0)
        {
            song = nullptr;
            return *this;
        }
        // associa ao title de song o title da última música de songs
        song = songs.getTail()->getValue();
        // remove a última música de songs
        songs.removeValue(songs.getTail()->getValue());
        // atualiza o valor de tail em songs
        auto damn = songs.getHead();
        while (damn->getNext() != nullptr)
        {
            damn = damn->getNext();
        }
        songs.setTail(damn);
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, Playlist &playlist)
    {
        os << playlist.getName() << std::endl;
        return os;
    }

    Playlist Playlist::operator+(Playlist &playlist)
    {
        Playlist newPlaylist = *this;
        auto aux = playlist.getSongs().getHead();
        while (aux != nullptr)
        {
            newPlaylist.addSong(aux->getValue());
            aux = aux->getNext();
        }
        return newPlaylist;
    }

    Playlist Playlist::operator+(Song &song)
    {
        addSong(song);
        return *this;
    }

    void Playlist::adicionaMusicas(Playlist &playlist)
    {
        auto aux = playlist.getSongs().getHead();
        while (aux != nullptr)
        {
            addSong(aux->getValue());
            aux = aux->getNext();
        }
    }

    void Playlist::removeMusicas(Playlist &playlist)
    {
        auto aux = playlist.getSongs().getHead();
        while (aux != nullptr)
        {
            removeSong(aux->getValue());
            aux = aux->getNext();
        }
    }

    Playlist::Playlist(const Playlist &playlist)
    {
        this->name = playlist.name;
        this->songs = playlist.songs;
    }

    Playlist Playlist::operator -(Playlist &playlist)
    {
        Playlist newPlaylist = *this;
        auto aux = playlist.getSongs().getHead();
        while (aux != nullptr)
        {
            newPlaylist.removeSong(aux->getValue());
            aux = aux->getNext();
        }
        return newPlaylist;
    }

    Playlist* Playlist::operator -(Song song)
    {
        removeSong(song);
        return this;
    }