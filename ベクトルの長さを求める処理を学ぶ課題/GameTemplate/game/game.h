/*!
 * @brief	ゲームクラス。
 */

#pragma once

#include "Player.h"

class Enemy;

/*!
 * @brief	ゲームクラス。
 */
class Game{
public:
	/*!
	 * @brief	コンストラクタ。
	 */
	Game();
	/*!
	 * @brief	デストラクタ。
	 */
	~Game();
	/*!
	 * @brief	ゲームが起動してから一度だけ呼ばれる関数。
	 */
	void Start();
	/*!
	 * @brief	更新。
	 */
	void Update();
	/*!
	 * @brief	描画。
	 */
	void Render();
	/*!
	* @brief	カメラを取得。
	*/
	Camera* GetCamera()
	{
		return &camera;
	}
private:
	Camera camera;
	Player player;
	std::list<Enemy*> enemyList;	//敵
};

extern Game* game;