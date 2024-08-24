#include "player.h"

using namespace std;

Player::Player()
{
    // Valores não definitivos.
    this->x = DISPLAY_WIDTH / 2;
    this->y = DISPLAY_HEIGHT / 2;
    this->dx = 0;
    this->dy = 0;
    this->life = 100;
    this->ammunition = 100;
    this->shotDelay = 0;
    this->isMoving = false;
    this->destinationX = DISPLAY_WIDTH / 2;
    this->destinationY = DISPLAY_HEIGHT / 2;
}

Player::~Player()
{
    // this->deinit();
}

void Player::update()
{
    if (this->isMoving)
        this->stopIfAtDestination();
    this->x += this->dx;
    this->y += this->dy;
    if (this->shotDelay > 0)
        this->shotDelay--;
}
void Player::render()
{
    ALLEGRO_BITMAP *sprite = al_load_bitmap("./src/assets/images/jogador.png");

    if (sprite)
    {
        int largura_sprite = al_get_bitmap_width(sprite);
        int altura_total = al_get_bitmap_height(sprite);
        int altura_frame = altura_total / 3;

        static int frame_atual = 0;
        static double ultimo_tempo = 0.0;
        double tempo_atual = al_get_time();

        if (tempo_atual - ultimo_tempo >= 0.6)
        {
            frame_atual = (frame_atual + 1) % 3;
            ultimo_tempo = tempo_atual;
        }

        int posicao_y = frame_atual * altura_frame;

        // Cria um sub-bitmap
        ALLEGRO_BITMAP *frame_cortado = al_create_sub_bitmap(sprite, 0, posicao_y, largura_sprite, altura_frame);

        if (frame_cortado)
        {
            // Calcula o ângulo
            float angulo = atan2(this->y - destinationY, this->x - destinationX) + ALLEGRO_PI;

            // Desenha o frame
            al_draw_rotated_bitmap(
                frame_cortado,
                largura_sprite / 2,
                altura_frame / 2,
                this->x, this->y,
                angulo,
                0);

            al_destroy_bitmap(frame_cortado);
        }

        al_destroy_bitmap(sprite);
    }
}

void Player::reset()
{
    this->x = DISPLAY_WIDTH / 2;
    this->y = DISPLAY_HEIGHT / 2;
    this->dx = 0;
    this->dy = 0;
    this->life = 100;
    this->ammunition = 100;
    this->shotDelay = 0;
    this->isMoving = false;
    this->destinationX = DISPLAY_WIDTH / 2;
    this->destinationY = DISPLAY_HEIGHT / 2;
}

// Mecânica

bool Player::move(int destinationX, int destinationY)
{
    int percursoX = destinationX - this->x;
    int percursoY = destinationY - this->y;

    // Caso já esteja no mesmo lugar do clique, não continua a execução
    if (abs(percursoX) <= 3 && abs(percursoY) <= 3)
        return false;

    float hipotenusa = sqrt((percursoX * percursoX) + (percursoY * percursoY));

    float tempo = hipotenusa / 3;

    float velocidadeX = percursoX / tempo;
    float velocidadeY = percursoY / tempo;

    this->dx = velocidadeX;
    this->dy = velocidadeY;
    this->destinationX = destinationX;
    this->destinationY = destinationY;

    this->isMoving = true;

    return true;
}

void Player::stopIfAtDestination()
{
    // Se o player estiver se movimentando e chegar no range de destino, seta a velocidade dx como 0.
    if (this->x <= this->destinationX + 2 && this->x >= this->destinationX - 2)
        this->dx = 0;

    // Se o player estiver se movimentando e chegar no range de destino, seta a velocidade dy como 0.
    if (this->y <= this->destinationY + 2 && this->y >= this->destinationY - 2)
        this->dy = 0;
}

void Player::shot()
{
    if (this->ammunition > 0 && this->shotDelay == 0)
    {
        this->ammunition--;
        // Valor arbitrário
        this->shotDelay = 10;
    }
}

// Getters and Setters

float Player::getPositionX()
{
    return this->x;
}

void Player::setPositionX(float x)
{
    this->x = x;
}

float Player::getPositionY()
{
    return this->y;
}

void Player::setPositionY(float y)
{
    this->y = y;
}

float Player::getDX()
{
    return this->dx;
}

void Player::setDX(float dx)
{
    this->dx = dx;
}

float Player::getDY()
{
    return this->dy;
}

void Player::setDY(float dy)
{
    this->dy = dy;
}

short Player::getAmmunition()
{
    return this->ammunition;
}

void Player::setAmmunition(short ammunition)
{
    this->ammunition = ammunition;
}

short Player::getShotDelay()
{
    return this->shotDelay;
}

void Player::setShotDelay(short shotDelay)
{
    this->shotDelay = shotDelay;
}

short Player::getLife()
{
    return this->life;
}
void Player::setLife(short life)
{
    this->life = life;
}

float Player::getDestinationX()
{
    return this->destinationX;
}
void Player::setDestinationX(float destinationX)
{
    this->destinationX = destinationX;
}

float Player::getDestinationY()
{
    return this->destinationY;
}
void Player::setDestinationY(float destinationY)
{
    this->destinationY = destinationY;
}