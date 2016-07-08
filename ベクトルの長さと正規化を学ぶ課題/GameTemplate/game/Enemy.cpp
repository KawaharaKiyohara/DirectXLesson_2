#include "stdafx.h"
#include "Enemy.h"
#include "game.h"
#include "bullet.h"

SkinModelData* Enemy::modelData = NULL;
const int BULLET_FIRE_INTERVAL = 2;
Enemy::Enemy()
{
	bulletFireInterval = BULLET_FIRE_INTERVAL;
}


Enemy::~Enemy()
{
	delete modelData;
	modelData = NULL;
}
void Enemy::Start(const D3DXVECTOR3& pos)
{
	position = pos;
	//ライトを初期化。
	light.SetDiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetDiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetDiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetAmbientLight(D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));

	if (modelData == NULL) {
		//モデルをロード。
		modelData = new SkinModelData;
		modelData->LoadModelData("Assets/model/DarkUnity.X", NULL);
	}

	model.Init(modelData);
	model.SetLight(&light);
}
bool Enemy::Update()
{
	const auto& bulletList = game->GetPlayerBullet();
	for (auto bullet : bulletList) {
		D3DXVECTOR3 diff = bullet->GetPosition() - position;
		float len = D3DXVec3Length(&diff);
		if (len < 0.2f) {
			return false;
		}
	}
	bulletFireInterval--;
	if (bulletFireInterval < 0) {
		if ((rand() % 100) < 2) {
			//10フレームに一度2%の確率で弾丸を射出する。
			Bullet* bullet = new Bullet;
			D3DXVECTOR3 bulletPos = position;
			bullet->Start(bulletPos, D3DXVECTOR3(0.0f, -0.05f, 0.0f));
			game->AddEnemyBullets(bullet);
		}
		bulletFireInterval = BULLET_FIRE_INTERVAL;
	}
	return true;
}
void Enemy::Render()
{
	model.UpdateWorldMatrix(position, D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	Camera* camera = game->GetCamera();
	model.Draw(&camera->GetViewMatrix(), &camera->GetProjectionMatrix());
}
