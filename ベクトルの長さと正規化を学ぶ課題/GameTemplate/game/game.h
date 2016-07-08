/*!
 * @brief	�Q�[���N���X�B
 */

#pragma once

#include "Player.h"

class Enemy;
class Bullet;

/*!
 * @brief	�Q�[���N���X�B
 */
class Game{
public:
	/*!
	 * @brief	�R���X�g���N�^�B
	 */
	Game();
	/*!
	 * @brief	�f�X�g���N�^�B
	 */
	~Game();
	/*!
	 * @brief	�Q�[�����N�����Ă����x�����Ă΂��֐��B
	 */
	void Start();
	/*!
	 * @brief	�X�V�B
	 */
	void Update();
	/*!
	 * @brief	�`��B
	 */
	void Render();
	/*!
	* @brief	�J�������擾�B
	*/
	Camera* GetCamera()
	{
		return &camera;
	}
	/*!
	* @brief	�v���C���[���������e��ǉ��B
	*/
	void AddPlayerBullets(Bullet* bullet)
	{
		playerBullets.push_back(bullet);
	}
	/*!
	* @brief	�G���������e��ǉ��B
	*/
	void AddEnemyBullets(Bullet* bullet)
	{
		enemyBullets.push_back(bullet);
	}
	/*!
	* @brief	�v���C���[���������e�̃��X�g���擾�B
	* @code
		�T���v���R�[�h
		const std::list<Bullet*>& bulletList = game->GetPlayerBullet();
		for(auto bullet : bulletList){
			bullet->Render();
        }
 	  @endcode
	*/
	const std::list<Bullet*>& GetPlayerBullet()
	{
		return playerBullets;
	}
	/*!
	* @brief	�G���������e�̃��X�g���擾�B
	*/
	const std::list<Bullet*>& GetEnemyBullet()
	{
		return enemyBullets;
	}
private:
	Camera camera;
	Player player;
	std::list<Enemy*> enemyList;	//�G
	std::list<Bullet*> playerBullets;	//�v���C���[�����˂����e
	std::list<Bullet*> enemyBullets;	//�G�����˂����e�ہB
};

extern Game* game;