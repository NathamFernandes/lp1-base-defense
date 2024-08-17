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

_Compilação atual Windows:_

```
g++ -I ./include .\src\main.cpp .\src\game.cpp .\src\model\shot.cpp .\src\model\enemy.cpp .\src\model\player.cpp .\src\model\base.cpp .\src\model\drop.cpp .\src\utils\random.cpp -o game.exe -lallegro -lallegro_font -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec
```

Créditos da música: https://opengameart.org/content/grey-sector-8-bit
