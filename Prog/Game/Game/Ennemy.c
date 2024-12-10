#include "../Game/Ennemy.h"
#include "../Libs/Utilities.h"
#include "../Libs/Collision.h"
#include "../Libs/Text.h"

Ennemy ennemy = { 0 };

void EnnemySetState(EnnemyState const _state);
void UpdateEnnemyAnimation(float _dt);
void CollideMouseEnnemy(sfRenderWindow* _render);
void RespawnEnnemy(void);

void LoadEnnemy(void)
{
	//ennemy.anim.idle = LoadAnimation("assets/ennemy_idle.png", 4, 0.2f);
	//ennemy.anim.walk = LoadAnimation("assets/ennemy_walk.png", 6, 0.1f);
	//ennemy.anim.attack = LoadAnimation("assets/ennemy_attack.png", 5, 0.15f);
	//ennemy.anim.hurt = LoadAnimation("assets/ennemy_hurt.png", 2, 0.2f);
	//ennemy.anim.dead = LoadAnimation("assets/ennemy_dead.png", 4, 0.25f);
	//ennemy.anim.current = &ennemy.anim.idle;

	RespawnEnnemy();
}

// Mise à jour de l'ennemi (position, état, animation)
void UpdateEnnemy(float _dt)
{
	if (ennemy.shootCooldown > 0.0f)
		ennemy.shootCooldown -= _dt;

	if (ennemy.shootCooldown <= 0 && ennemy.state != DEAD)
	{
		EnnemyShoot();
		ennemy.shootCooldown = SHOOT_COOLDOWN;
	}

	if (ennemy.state == WALK)
	{
		ennemy.position.x -= ennemy.velocity.x * _dt;
	}

	UpdateEnnemyAnimation(_dt);
}

// Gestion du tir de l'ennemi
void EnnemyShoot(void)
{
	EnnemySetState(ATTACK);
}

// Dessin de l'ennemi sur la fenêtre
void DrawEnnemy(sfRenderWindow* _render)
{
	//sfRenderWindow_drawSprite(_render, ennemy.anim.current, NULL);
}

// Définit un nouvel état pour l'ennemi
void EnnemySetState(EnnemyState const _state)
{
	if (ennemy.state == _state) return;

	ennemy.state = _state;

	switch (_state)
	{
	case IDLE:
		ennemy.anim.current = &ennemy.anim.idle;
		break;
	case WALK:
		ennemy.anim.current = &ennemy.anim.walk;
		break;
	case ATTACK:
		ennemy.anim.current = &ennemy.anim.attack;
		break;
	case HURT:
		ennemy.anim.current = &ennemy.anim.hurt;
		break;
	case DEAD:
		ennemy.anim.current = &ennemy.anim.dead;
		break;
	}
}

// Mise à jour de l'animation en fonction de l'état
void UpdateEnnemyAnimation(float _dt)
{
	UpdateAnimation(&ennemy.anim.current, _dt);
}

// Gestion des collisions entre le clic souris et l'ennemi
void CollideMouseEnnemy(sfRenderWindow* _render)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(_render);
	sfFloatRect enemyHitbox = (sfFloatRect){ .left = ennemy.position.x, .top = ennemy.position.y, .width = 64, .height = 64 };

	if (sfMouse_isButtonPressed(sfMouseLeft) && sfFloatRect_contains(&enemyHitbox, mouse.x, mouse.y))
	{
		EnnemySetState(HURT);
		ennemy.health -= 1;

		if (ennemy.health <= 0)
		{
			EnnemySetState(DEAD);
		}
	}
}

void RespawnEnnemy(void)
{
	ennemy.position = (sfVector2f){ SCREEN_W + (rand() % 200), 600 };
	ennemy.velocity = (sfVector2f){ BASE_VELOCITY + (rand() % 100), 0 };
	ennemy.health = SOLDIERS_HEALTH;
	ennemy.shootCooldown = SHOOT_COOLDOWN;
	ennemy.state = WALK;
}
