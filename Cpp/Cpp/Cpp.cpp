
#include <iostream>
#include <vector>
#include <map>

class GameObject;  // 前方宣言

// コンポーネントの基底クラス
class Component {
public:
    virtual ~Component() = default;

    // 更新処理
    virtual void update(GameObject& owner) {}
    // 描画処理
    virtual void render(GameObject& owner) {}
};

// ゲームオブジェクトクラス
// GameObject クラス
class GameObject {
public:
    GameObject(std::string_view name)
        : name_(name) {
    }

public:
    // ゲームオブジェクトの名前を取得する
    std::string_view getName() const { return name_; }

    // コンポーネント名を指定してコンポーネントを登録する
    void addComponent(std::string_view name, Component* component) {
        components_[name.data()].reset(component);
    }

    // コンポーネント名を指定してコンポーネントを取得する
    Component* getComponent(std::string_view name) {
        auto it = components_.find(name.data());
        if (it != components_.end()) {
            return it->second.get();
        }
        return nullptr;
    }

    // 更新処理
    void update() {
        // 各コンポーネントの update を呼び出す
        for (auto& pair : components_) {
            pair.second->update(*this);
        }
    }

    // 描画処理
    void render() {
        // 各コンポーネントの render を呼び出す
        for (auto& pair : components_) {
            pair.second->render(*this);
        }
    }

private:
    std::string                                       name_;        // ゲームオブジェクトの名前
    std::map<std::string, std::unique_ptr<Component>> components_;  // コンポーネントを名前で管理するためのマップ
};


class TransformComponent : public Component {
public:
    // 更新処理
    void update(GameObject& owner) override {
        // Owner に位置を反映する処理など
    }

    // 描画処理
    void render(GameObject& owner) override {
        printf("座標：(%.2f, %.2f)\n", x_, y_);
    }

public:
    // 位置を移動させる
    void move(float dx, float dy) {
        x_ += dx;
        y_ += dy;
    }

private:
    // 移動に必要な座標をメンバー変数として保持する
    float x_{};
    float y_{};
};

// HP 管理を担うコンポーネント
class HealthComponent : public Component {
public:
    // 描画処理
    void render(GameObject& owner) override {
        printf("体力：%d / %d\n", hp_, maxHp_);
    }

public:
    // HP を設定する
    void setMaxHp(int maxHp) {
        maxHp_ = maxHp;
        hp_ = maxHp_;
    }

    // ダメージ処理
    void damage(int damage) {
        hp_ = std::max(0, hp_ - damage);
    }

    // HP を取得する
    int getHp() const { return hp_; }

    // 死亡したかどうか
    bool isDead() const { return hp_ <= 0; }

private:
    // HP 管理に必要な情報をメンバー変数で保持する
    int hp_{};
    int maxHp_{};
};

// 描画を担うコンポーネント
class RenderComponent : public Component {
public:
    // 描画処理
    // 更新処理は行わないので、update はオーバーライドしない
    void render(GameObject& owner) override {
        printf("名前：%s\n", owner.getName().data());
    }
};


int main()
{
   //プレイヤー
    GameObject player("player");

    player.addComponent("draw", new RenderComponent());
    player.addComponent("trans", new TransformComponent());
    player.addComponent("hp", new HealthComponent());

    //背景
    GameObject staticProp("StaticProp");
    staticProp.addComponent("render", new RenderComponent());

    //罠
    GameObject trap("Trap");
    trap.addComponent("render", new RenderComponent());
    trap.addComponent("trans", new TransformComponent());

    auto hp = static_cast<HealthComponent*>(player.getComponent("hp"));
    hp->setMaxHp(100);
    player.render();
}

