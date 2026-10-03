
#include <iostream>
#include <map>

// プレイヤークラス
class Player {
public:
    void moveForward() { /* 前方に移動する処理 */ }
    void jump(float power) { /* ジャンプする処理 */ }
};

// コマンド基底クラス
class Command {
public:
    virtual ~Command() {}
    // コマンドを実行するための純粋仮想関数
    virtual void execute(Player& player) = 0;
};

// 前方に移動するコマンド
class MoveForwardCommand : public Command {
public:
    // プレイヤーを前方に移動させる処理を実装
    void execute(Player& player) override {
        player.moveForward();
    }
};

// ジャンプするコマンド
class JumpCommand : public Command {
public:
    // プレイヤーをジャンプさせる処理を実装
    void execute(Player& player) override {
        player.jump(jumpPower_);
    }

private:
    float jumpPower_ = 1.0f; // ジャンプ力
};

class InputHandler {
public:
    InputHandler(std::shared_ptr<Player> player)
        : player_(player) {
    }

    // キーとコマンドを紐付ける（キーコンフィグ）
    void setCommand(int key, Command* command) {
        bindings_[key].reset(command);
    }

    // 入力を監視し、対応するコマンドを実行する
    void update() {
        for (auto& [key, command] : bindings_) {
            //if (input.isPressed(key)) {
                command->execute(*player_);
            //}
        }
    }

private:
    std::map<int, std::unique_ptr<Command>> bindings_{};  // キーとコマンドの紐付け
    std::shared_ptr<Player>                 player_{};    // プレイヤーへの参照
};

int main()
{
    auto player = std::make_shared<Player>();

    InputHandler handler(player);
    handler.setCommand(0, new MoveForwardCommand());
    handler.setCommand(1, new JumpCommand());

    handler.update();

    handler.setCommand(0, new JumpCommand());

    handler.update();
}

