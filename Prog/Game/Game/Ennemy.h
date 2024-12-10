#ifndef ENNEMY_H
#define ENNEMY_H

#include "../Libs/Common.h"
#include "../Libs/Animations.h"
#include "../Libs/Collision.h"

// État des ennemis
typedef enum EnnemyState
{
    IDLE,
    WALK,
    ATTACK,
    HURT,
    DEAD
} EnnemyState;

// Type d'objet lâché par un ennemi
typedef enum DropType
{
    NONE,
    AMMO,
    HEALTH
} DropType;

// Structure des animations de l'ennemi
typedef struct EnnemyAnim
{
    Animation idle;
    Animation walk;
    Animation hurt;
    Animation attack;
    Animation dead;
    Animation* current;
} EnnemyAnim;

// Structure principale de l'ennemi
typedef struct Ennemy
{
    EnnemyAnim anim;           
    EnnemyState state;        
    sfVector2f position;       
    sfVector2f velocity;       
    float health;              
    float shootCooldown;       
    int scoreValue;            
    DropType drop;            
    sfBool isActive;          
} Ennemy;


void LoadEnnemy(void);

void UpdateEnnemy(float _dt);

void DrawEnnemy(sfRenderWindow* _render);

void EnnemyShoot(void);

//void HandleEnnemyDeath(void);

#endif
