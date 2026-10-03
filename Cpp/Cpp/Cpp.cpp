
#include <iostream>

class Enemy {
public:
    virtual void initialize() {};
};

class Dragon : public Enemy {
public:
    void initialize() override {};
};

class Goblin : public Enemy {
public:
    void initialize() override {};
};

class Knight : public Enemy {
public:
    void initialize() override {};
};

class King : public Enemy {
public:
    void initialize() override {};
};

// 敵生成基底クラス
// 生成の枠組みだけを定義する
class EnemySpawner {
public:
    EnemySpawner() = default;
    virtual ~EnemySpawner() = default;

    // 敵の生成と初期化まで行う流れを定義
    std::unique_ptr<Enemy> spawnEnemy() {
        auto enemy = createEnemy(); // 生成はサブクラスに任せる
        enemy->initialize();
        return enemy;
    }

    // ボスの生成と初期化まで行う流れを定義
    std::unique_ptr<Enemy> spawnBoss() {
        auto boss = createBoss(); // 生成はサブクラスに任せる
        boss->initialize();
        return boss;
    }

protected:
    // 派生先が具体的な生成を担う
    virtual std::unique_ptr<Enemy> createEnemy() = 0;
    virtual std::unique_ptr<Enemy> createBoss() = 0;
};

// 森の敵生成クラス
class ForestEnemySpawner : public EnemySpawner {
protected:
    // 森の敵はゴブリン（具体的な生成を実装する）
    std::unique_ptr<Enemy> createEnemy() override {
        return std::make_unique<Goblin>();
    }

    // 森のボスはドラゴン（具体的な生成を実装する）
    std::unique_ptr<Enemy> createBoss() override {
        return std::make_unique<Dragon>();
    }
};

// 城の敵生成クラス
class CastleEnemySpawner : public EnemySpawner {
protected:
    // 城の敵はナイト（具体的な生成を実装する）
    std::unique_ptr<Enemy> createEnemy() override {
        return std::make_unique<Knight>();
    }

    // 城のボスはキング（具体的な生成を実装する）
    std::unique_ptr<Enemy> createBoss() override {
        return std::make_unique<King>();
    }
};

int main()
{
    // 呼び出し側は Spawner の種類だけを意識する
    std::unique_ptr<EnemySpawner> spawner{};

    // 森の敵生成クラスの生成
    {
        spawner = std::make_unique<ForestEnemySpawner>();
        // ゴブリンとドラゴンが生成される
        auto enemy = spawner->spawnEnemy();
        auto boss = spawner->spawnBoss();
    }

    {
        spawner = std::make_unique<CastleEnemySpawner>();

        auto enemy = spawner->spawnEnemy();//Knight
        auto boss = spawner->spawnBoss();  //king
    }
}

