/*!
 * @brief	�Q�[��
 */
#include "stdafx.h"
#include "game.h"
#include "Enemy.h"

/*!
 * @brief	�R���X�g���N�^�B
 */
Game::Game()
{
}
/*!
 * @brief	�f�X�g���N�^�B
 */
Game::~Game()
{
	for (auto enemy : enemyList) {
		delete enemy;
	}
}
/*!
 * @brief	�Q�[�����N�����Ă����x�����Ă΂��֐��B
 */
void Game::Start()
{
	//�J�����������B
	camera.Init();
	camera.SetEyePt(D3DXVECTOR3(0.0f, 3.0f, 10.0f));
	camera.SetLookatPt(D3DXVECTOR3(0.0f, 3.0f, 0.0f));
	camera.Update();

	player.Start();
	//�_�[�N���j�e�B������z�u
	for (int i = 0; i < 10; i++) {
		Enemy* enemy = new Enemy;
		enemyList.push_back(enemy);
		
		enemy->Start(D3DXVECTOR3(-3.5f + 0.8f * i, 6.0f, 0.0f));
	}

}
/*!
 * @brief	�X�V�B
 */
void Game::Update()
{
	for (auto enemy : enemyList) {
		enemy->Update();
	}
	player.Update();
	camera.Update();
}
/*!
 * @brief	�`��B
 */
void Game::Render()
{
	for (auto enemy : enemyList) {
		enemy->Render();
	}
	player.Render();
}
