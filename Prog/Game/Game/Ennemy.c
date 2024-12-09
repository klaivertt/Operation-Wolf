#include "../Game/Ennemy.h"
#include "../Libs/Utilities.h"
#include "../Libs/Collision.h"
#include "../Libs/Text.h"

Ennemy ennemy = { 0 };

void EnnemySetState(EnnemyState const _state);
void UpdateEnnemyAnimation();
void HeathUpdate();
void CollideMouseEnnemy(sfRenderWindow* _render);
void RespawnEnnemy(void);

void LoadEnnemy(void)
{

}

void UpdateEnnemy(float _dt)
{
	
}



void DrawEnnemy(sfRenderWindow* _render)
{

}

void EnnemySetState(EnnemyState const _state)
{
	ennemy.state = _state;
}

void UpdateEnnemyAnimation()
{
	switch (ennemy.state)
	{
	case IDLE:
	
		break;
	case WALK:
		
		break;
	case HURT:
		
		break;
	case ATTACK:
		
		break;
	case DEAD:
		
		break;
	default:
		break;
	}

}

void CollideMouseEnnemy(sfRenderWindow* _render)
{
	//sfFloatRect enemyHitbox = sfSprite_getGlobalBounds(ennemy.anim.current->sprite);
	sfVector2i mouse = sfMouse_getPositionRenderWindow(_render);	
}


void RespawnEnnemy(void)
{
	// Réinitialiser les attributs de l'ennemi
}
