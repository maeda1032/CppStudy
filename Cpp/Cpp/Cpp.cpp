
#include <iostream>

class SoundManager {
public:
    // 唯一のインスタンスを返す静的関数
    static SoundManager& getInstance() {
        // 初回呼び出し時のみ生成される。以降は同じインスタンスを返す。
        static SoundManager instance;
        return instance;
    }

    void playSound(std::string_view soundName) { /* 再生処理 */ }
    void setVolume(float volume) { masterVolume_ = volume; }

private:
    SoundManager() = default;

    // コピーと代入を禁止する
    SoundManager(const SoundManager&) = delete;
    SoundManager& operator=(const SoundManager&) = delete;

private:
    float masterVolume_{};
};

int main()
{
    SoundManager::getInstance().playSound("a");
}

