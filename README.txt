Projeto 1 - Playlists

Autor: Pedro Vinícius Oliveira Maciel Pinho



O programa permite a criação de músicas e playlists, e também permite 
"tocar" as músicas de uma playlist, mostrando sempre qual a próxima
música a ser tocada.

Uma limitação do programa é que não é possível ter duas músicas
diferentes com mesmo nome, mesmo que o autor das duas seja diferente.

Ao rodar o programa, é possível executar o setup, que automaticamente
adiciona algumas playlists e músicas para teste.

Esses são os dados adicionados no setup:

Playlist 1: Música 1, Música 2 e Música 3.

Playlist 2: Música 1 e Música 4.

Playlist 3: Nenhuma música.



A documentação doxygen do projeto está disponível no arquivo docs/html/index.html



Como compilar:

Na pasta raiz do projeto, utilize os comandos a seguir:

cmake -B build
cmake --build build

Como rodar:

Utilize o comando a seguir:

./build/program