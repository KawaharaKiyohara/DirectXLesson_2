#include "stdafx.h"
#include "CourceDef.h"


//�R�[�X��`�̃f�[�^�\���́B
struct CourceDefData{
	D3DXVECTOR3 startPos;		//�n�_�B
	D3DXVECTOR3 endPos;			//�I�_�B
};
//�R�[�X��`�̃f�[�^�e�[�u���B
static CourceDefData datas[] = {
	{
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
	},
};
CourceDef::CourceDef()
{
}


CourceDef::~CourceDef()
{
}
