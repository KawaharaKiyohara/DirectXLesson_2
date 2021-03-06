#pragma once

#include "Turn.h"

class Player
{
public:
	Player();
	~Player();
	void Start();
	void Update();
	void Render();
	void ExecuteTurn(D3DXVECTOR3 moveDir);
	const D3DXVECTOR3& GetPosition() const
	{
		return position;
	}
private:
	SkinModel model;
	SkinModelData modelData;
	Animation animation;
	D3DXVECTOR3 position;			//座標
	D3DXQUATERNION rotation;		//回転	
	D3DXVECTOR3 currentDirection;	//現在の方向。
	D3DXQUATERNION baseRot;
	Light light;
	Turn  turn;						//旋回処理。
};

