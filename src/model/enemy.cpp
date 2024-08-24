#include "enemy.h"

#include <iostream>

using namespace std;

Enemy::Enemy()
{
    this->life = ENEMY_LIFE;
    this->used = false;
    this->defineRandomPosition();
    this->shotDelay = 100;
}

bool Enemy::isUsed()
{
    return this->used;
}

void Enemy::setUsed(bool used)
{
    this->used = used;
}

float Enemy::getVelocity()
{
    return this->velocity;
}

void Enemy::setVelocity(float velocity)
{
    this->velocity = velocity;
}

void Enemy::defineRandomPosition()
{
    this->direction = (Direction)Random::randint(0, LAST);

    switch (this->direction)
    {
    case TOP:
        this->setPositionX(Random::randint(0, DISPLAY_WIDTH));
        this->setPositionY(0);
        break;
    case RIGHT:
        this->setPositionX(DISPLAY_WIDTH);
        this->setPositionY(Random::randint(0, DISPLAY_HEIGHT));
        break;
    case BOTTOM:
        this->setPositionX(Random::randint(0, DISPLAY_WIDTH));
        this->setPositionY(DISPLAY_HEIGHT);
        break;
    case LEFT:
        this->setPositionX(0);
        this->setPositionY(Random::randint(0, DISPLAY_HEIGHT));
        break;
    default:
        break;
    }
}

void Enemy::updatePosition(int playerPositionX, int playerPositionY)
{
    if (
        this->getPositionX() + 30 >= playerPositionX &&
        this->getPositionX() - 30 <= playerPositionX &&
        this->getPositionY() + 30 >= playerPositionY &&
        this->getPositionY() - 30 <= playerPositionY)
    {
        this->dx = 0;
        this->dy = 0;
        return;
    }

    int percursoX = playerPositionX - this->x;
    int percursoY = playerPositionY - this->y;

    float hypot = sqrt(pow(percursoX, 2) + pow(percursoY, 2));

    float time = hypot / this->getVelocity();

    float xVelocity = percursoX / time;
    float yVelocity = percursoY / time;

    this->dx = xVelocity;
    this->dy = yVelocity;
}

int Enemy::getPositionX()
{
    return this->x;
}

void Enemy::setPositionX(int x)
{
    this->x = x;
}

int Enemy::getPositionY()
{
    return this->y;
}

void Enemy::setPositionY(int y)
{
    this->y = y;
}
void Enemy::render()
{
    if (!this->isUsed())
        return;

    ALLEGRO_BITMAP* sprite = al_load_bitmap("./inimigo.png");

    if (sprite) {
        int largura_sprite = al_get_bitmap_width(sprite);
        int altura_total = al_get_bitmap_height(sprite);
        int altura_frame = altura_total / 3;  

        static int frame_atual = 0; 
        static double ultimo_tempo = 0.0;  
        double tempo_atual = al_get_time();  

        
        if (tempo_atual - ultimo_tempo >= 0.5) {
            frame_atual = (frame_atual + 1) % 3;  
            ultimo_tempo = tempo_atual;  
        }

 
        int posicao_y = frame_atual * altura_frame;

        ALLEGRO_BITMAP* frame_cortado = al_create_sub_bitmap(sprite, 0, posicao_y, largura_sprite, altura_frame);

        if (frame_cortado) {
            float angulo = atan2(this->y , this->x) + ALLEGRO_PI;

            al_draw_rotated_bitmap(
                frame_cortado,         
                largura_sprite / 2,    
                altura_frame / 2,      
                this->x, this->y,      
                angulo,                
                0                      
            );

            al_destroy_bitmap(frame_cortado);
        }

        al_destroy_bitmap(sprite);
    }
}



void Enemy::update(int playerPositionX, int playerPositionY)
{
    this->updatePosition(playerPositionX, playerPositionY);

    if (this->life <= 0)
    {
        this->setUsed(false);
        return;
    }

    // TODO: Adicionar lógica de colisão com os tiros do herói

    this->x += this->dx;
    this->y += this->dy;

    if (this->shotDelay > 0)
        this->shotDelay--;
}

short Enemy::getShotDelay()
{
    return this->shotDelay;
}

void Enemy::setShotDelay(short shotDelay)
{
    this->shotDelay = shotDelay;
}