/*!
 * @brief	ゲームクラス。
 */

#pragma once

#include "Player.h"

class Enemy;
class Bullet;

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
	/*!
	* @brief	プレイヤーが放った弾を追加。
	*/
	void AddPlayerBullets(Bullet* bullet)
	{
		playerBullets.push_back(bullet);
	}
	/*!
	* @brief	敵が放った弾を追加。
	*/
	void AddEnemyBullets(Bullet* bullet)
	{
		enemyBullets.push_back(bullet);
	}
	/*!
	* @brief	プレイヤーが放った弾のリストを取得。
	* @code
		サンプルコード
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
	* @brief	敵が放った弾のリストを取得。
	*/
	const std::list<Bullet*>& GetEnemyBullet()
	{
		return enemyBullets;
	}
private:
	Camera camera;
	Player player;
	std::list<Enemy*> enemyList;	//敵
	std::list<Bullet*> playerBullets;	//プレイヤーが発射した弾
	std::list<Bullet*> enemyBullets;	//敵が発射した弾丸。
};

extern Game* game;