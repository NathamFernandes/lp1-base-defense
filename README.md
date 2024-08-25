# LP1 BASE DEFENSE

LP1 Base Defense é um jogo implementado utilizando a linguagem de programação C++ e a biblioteca [Allegro](https://liballeg.org/), como projeto final da disciplina **IMD0030 - LINGUAGEM DE PROGRAMAÇÃO I** ministrada pelo professor Isaac Franco.

Componentes:

- Arthur Emanuel Souza Cassiano da Costa (https://github.com/arthurcostaa)
- Erivaldo Oliveira dos Reis
- Natham Fernandes Raquel (https://github.com/NathamFernandes)

Link para o vídeo abaixo:
[VideoLP1](https://drive.google.com/file/d/1L6u8cbI9IQd00fwh_1d1zEKZ_XOq_Xal/view?usp=sharing)

## Pré-requisitos

Para executar esse jogo é necessário instalar a biblioteca
[Allegro](https://liballeg.org/). Acesse o seguinte endereço para mais
informações sobre como instalar a biblioteca no seu sistema operacional:
https://github.com/liballeg/allegro_wiki/wiki/Quickstart#installation.

Certifique-se também que você tem instalado o compilador da linguagem C++, o `g++` para compilar o jogo.

## Compilação e Execução no Linux

Para compilar e executar o jogo é necessário ter a ferramenta `make`.

Execute o seguinte comando para compilar:

```
make
```

Para executar execute o seguinte comando:

```
make run
```

## Compilação e Execução no Windows

Para compilar o jogo no Windows, é necessário ter instalada a biblioteca do Allegro. Para isso, uma das formas é instalar utilizando o [MINGW64](https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/) e pegando o pacote do [repositório do MYSYS2](https://packages.msys2.org/base/mingw-w64-allegro). Para isso, abra o terminal **MYSYS2 MING64** (ver documentação para versões 32 bits) e instale a biblioteca com o seguinte comando:

```
pacman -S mingw-w64-x86_64-allegro
```

Após isso, feche e abra os terminais abertos. Depois dos procedimentos, certamente será possível compilar programas Allegro. Note que, no Windows, o comando para compilação necessita de flags diferentes (a depender das funcionalidades utilizadas) em comparação aos sistemas Linux.

Segue abaixo o comando para compilação deste projeto no Windows:

```
g++ -I ./include .\src\main.cpp .\src\game.cpp .\src\model\shot.cpp .\src\model\enemy.cpp .\src\model\player.cpp .\src\model\base.cpp .\src\model\drop.cpp .\src\utils\random.cpp -o game.exe -lallegro -lallegro_font -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec
```

## Recursos implementados

Os recursos implementados no jogo consistem em:

- **Movimentação do jogador**: a movimentação do jogador foi feita utilizando o botão direito do mouse. Portanto, para levá-lo até um local destino basta clicar no local desejado e ele se moverá até lá.
- **Vida do jogador**: o jogador possui uma vida limitada a 100 pontos, que diminui quando ele é atingido por um tiro disparado por um inimigo, tirando-lhe 1 ponto de vida, ou quando o inimigo colide com o jogador, tirando-lhe 5 pontos de vida. A vida do jogador pode ser regenerada ao coletar os bônus deixados pelos inimigos morte e quando a sua vida for 0, acontece o _game over_.
- **Base**: a base fica no centro da tela e deve ser protegida pela jogador. Assim como o jogador ela também possui 100 pontos de vida, que diminuem quando ela é atingida por disparos dos inimigos ou quando um inimigo colide com ela. Ao longo do jogo, a cor da base muda, indicando o nível de dano que ela possui. Quando a vida da base chega a 0, ocorre o _game over_.
- **Inimigos**: a todo instante surgem inimigos que aparecem de regiões aleatórias nas bordas da tela. Eles sempre estarão perseguindo e atirando no jogador, tentando destruí-lo. Quando um inimigo atinge o jogador ou a base, ele automaticamente desaparece e desconta uma quantidade de vida maior do jogador ou da base.
- **Tiros**: tanto o jogador quanto o inimigo podem atirar, o jogador por sua vez tem uma quantidade limitada de tiros, enquanto que o inimigo não, porém esses tiros ocorrem de acordo com um intervalo pré-determinado. Ao longo do jogo, o jogador pode coletar os bônus que aparecem ao matar um inimigo e dessa forma será possível aumentar o seu estoque de tiro de forma ilimitada. Para que o jogador possa atirar basta apertar na tecla Q que o tiro seguirá a direção do ponteiro do mouse.
- **Bônus**: sempre que o jogador liquida um inimigo será deixado pelo inimigo um bônus, que ao ser coletado pelo jogador pode aumentar o seu estoque de munição, o nível de vida do próprio jogador ou a vida da base. O valor do bônus é aleatório e após um determinado período de tempo ele desaparece.
- **Fim de jogo**: o jogo possui um tempo de duração de 5 minutos e se o jogador sobreviver todo esse tempo ele será declarado vencedor.
- **Game over**: caso os níveis de vida da base ou do jogador cheguem a 0, então ocorre o game over.
- **Pause**: a pausa do jogo é feita apertando a tecla ESC e para voltar ao jogo basta apertar essa tecla novamente.
- **Efeitos sonoros e música**: o jogo possui diversos efeitos sonoros, como o de disparo de um tiro, coleta de bônus, quando o jogador ou o inimigo são atingidos por um tiro, quando a base ou o jogador colidem com um inimigo e também para o _game over_ e fim de jogo. Além disso, também há uma música de fundo durante todo o jogo.
- **Sprites**: tanto o jogador quanto os inimigos possuem sprites, que se diferenciam pelas suas cores.
- **Score board**: o jogo possui um _score board_ que indica o tempo de jogo, a vida da base e do jogador, o número de inimigos que o jogador matou e o estoque de munição.

## Recursos não implementados

No jogo não foi implementado os sprites para os bônus deixados pelos inimigos e também um sprite para a base.

## Créditos

### Música

https://opengameart.org/content/grey-sector-8-bit

### Sound Effects

- https://opengameart.org/content/50-cc0-retro-synth-sfx (Hits e Drops)
- https://opengameart.org/content/game-over-soundold-school (Game Over)
- https://opengameart.org/content/8-bit-sound-effects-library (Game Win/Finished)
