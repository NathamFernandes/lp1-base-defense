# LP1 BASE DEFENSE

## Pré-requisitos

Para executar esse jogo é necessário instalar a biblioteca
[Allegro](https://liballeg.org/). Acesse o seguinte endereço para mais
informações sobre como instalar a biblioteca no seu sistema operacional:
https://github.com/liballeg/allegro_wiki/wiki/Quickstart#installation.

## Compilação e Execução

Para compilar e executar o jogo é necessário ter a ferramenta `make`. No
diretório do projeto execute:

```
make
make run
```

### Compilação atual Windows

Para compilar o jogo no Windows, é necessário ter instalada a biblioteca do Allegro. Para isso, uma das formas é instalar utilizando o [MINGW64](https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/) e pegando o pacote do [repositório do MYSYS2](https://packages.msys2.org/base/mingw-w64-allegro). Para isso, abra o terminal **MYSYS2 MING64** (ver documentação para versões 32 bits) e instale a biblioteca com o seguinte comando:

```
pacman -S mingw-w64-x86_64-allegro
```

Após isso, feche e abra os terminais abertos. Depois dos procedimentos, certamente será possível compilar programas Allegro. Note que, no Windows, o comando para compilação necessita de flags diferentes (a depender das funcionalidades utilizadas) em comparação aos sistemas Linux.

Segue abaixo o comando para compilação deste projeto no Windows:

```
g++ -I ./include .\src\main.cpp .\src\game.cpp .\src\model\shot.cpp .\src\model\enemy.cpp .\src\model\player.cpp .\src\model\base.cpp .\src\model\drop.cpp .\src\utils\random.cpp -o game.exe -lallegro -lallegro_font -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec
```

#### Créditos

Música: https://opengameart.org/content/grey-sector-8-bit
Sound Effects:

- https://opengameart.org/content/50-cc0-retro-synth-sfx (Hits e Drops)
- https://opengameart.org/content/game-over-soundold-school (Game Over)
- https://opengameart.org/content/8-bit-sound-effects-library (Game Win/Finished)
