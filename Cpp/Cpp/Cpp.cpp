#include <iostream>

// プレイヤーの列挙
enum class Player {
    Hero,
};

// プレイヤーの列挙
enum class Enemy {
    Boss,
};

// プレイヤークラス
class PlayerChara {
public:
    PlayerChara() { std::cout << "プレイヤーを生成します" << std::endl; }
};
// 敵クラス
class EnemyChara {
public:
    EnemyChara() { std::cout << "敵を生成します" << std::endl; }
};
// NPC クラス
class NPCChara {
public:
    NPCChara() { std::cout << "NPCを生成します" << std::endl; }
};

// プレイヤーを生成する関数
std::unique_ptr<PlayerChara> createChara(Player player, int attack, float speed, char weaponId) {
    return std::make_unique<PlayerChara>();
}

// 敵を生成する関数
std::unique_ptr<EnemyChara> createChara(Enemy enemy, int attack, float speed) {
    return std::make_unique<EnemyChara>();
}

// NPCを生成する関数
std::unique_ptr<NPCChara> createChara() {
    return std::make_unique<NPCChara>();
}

// キャラクター生成のテンプレート関数
// 戻り値の型を後置宣言する方法を利用して、関数の結果から戻り値型を推論する
template <class... T>
auto create(T... args) {
    // パラメータパックを展開して対応する関数に渡す
    return createChara(args...);
}

// エントリー関数
int main() {
    // プレイヤーを生成する関数が呼び出される
    auto p = create(Player::Hero, 10, 1.0f, 3);

    // 敵を生成する関数が呼び出される
    auto e = create(Enemy::Boss, 10, 1.0f);

    // NPCを生成する関数が呼び出される
    auto n = create();

    return 0;
}