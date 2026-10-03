
#include <iostream>

class Player; // 前方宣言

// プレイヤー状態基底
class PlayerState {
public:
    PlayerState() = default;
    virtual ~PlayerState() = default;

    // 状態に入ったときに一度だけ呼ばれる
    virtual void enter(Player& player) {}

    // 毎フレーム呼ばれる
    virtual void update(Player& player) = 0;

    // 状態から出るときに一度だけ呼ばれる
    virtual void exit(Player& player) {}
};

class Player {
public:
    Player() = default;

    void update() {
        // 現在の状態に処理を任せる
        currentState_->update(*this);
    }

    void changeState(PlayerState* newState) {
        if (currentState_) {
            currentState_->exit(*this);
        }

        // 状態を切り替える
        currentState_.reset(newState);
        currentState_->enter(*this);
    }

    void playAnimation(const std::string& name) { /* アニメーション再生 */ }
    void move() { /* 移動処理 */ }
    bool jump() { /* ジャンプ落下処理、着地したら true を返す */ return false; }


private:
    std::unique_ptr<PlayerState> currentState_{}; // 現在の状態
};

class IdleState : public PlayerState {
public:
    // 状態に入ったときに一度だけ呼ばれる
    void enter(Player& player) override {
        player.playAnimation("idle");
    }

    // 毎フレーム呼ばれる
    void update(Player& player) override {
    }
};

// 移動状態
class MoveState : public PlayerState {
public:
    // 状態に入ったときに一度だけ呼ばれる
    void enter(Player& player) override {
        player.playAnimation("move");
    }

    // 毎フレーム呼ばれる
    void update(Player& player) override {
        player.move();
    }
};

// ジャンプ状態
class JumpState : public PlayerState {
public:
    // 状態に入ったときに一度だけ呼ばれる
    void enter(Player& player) override {
        player.playAnimation("jump");
    }

    // 毎フレーム呼ばれる
    void update(Player& player) override {
        player.jump();
    }
};

int main()
{
    Player player;
    player.changeState(new IdleState);
}

