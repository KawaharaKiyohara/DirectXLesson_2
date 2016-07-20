#include "stdafx.h"
#include "CourceDef.h"


//コース定義のデータ構造体。
struct CourceDefData{
	D3DXVECTOR3 startPos;		//始点。
	D3DXVECTOR3 endPos;			//終点。
};
//コース定義のデータテーブル。
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
