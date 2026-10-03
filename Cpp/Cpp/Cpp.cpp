
#include <iostream>
#include <vector>

// Observer (通知を受ける側) の基底クラス
class Observer {
public:
    virtual ~Observer() {}

    // 通知を受け取ったときに呼ばれる
    // event にはイベントの種類、value には付随するデータを渡す
    virtual void onNotify(std::string_view event, int value) = 0;
};

class ScoreUI : public Observer {
public:
	void onNotify(std::string_view event, int value) override {
		if (event == "SCORE_CHANGED") {
			printf("Score: %d\n", value);
		}
	}
};

// スコアマネージャー（様々なオブジェクトに通知を送る側）
class ScoreManager : public Subject {
public:
    // スコアを加算する
    void addScore(int points) {
        score_ += points;

        // 直接呼び出しがなくなり notify 一本になる
        notify("SCORE_CHANGED", score_);
    }

    // スコアを取得する
    int getScore() const { return score_; }

private:
    int score_ = 0;
};

// サウンド再生（通知を受ける側）
class SoundManager : public Observer {
public:
    //具体化した通知処理
    void onNotify(std::string_view event, int value) override {
        if (event == "SCORE_CHANGED") {
            // サウンドを再生する
            printf("playSound: %d\n", value);
        }
    }
};
		
class Subject {
public:
    // Observer 登録
    void addObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    // Observer 解除（指定した Observer だけをリストから取り除く）
    void removeObserver(Observer* observer) {
        std::erase(observers_, observer);
    }

protected:
    // 登録されている全 Observer に通知する
    void notify(std::string_view event, int value) {
        for (Observer* observer : observers_) {
            observer->onNotify(event, value);
        }
    }

private:
    // Observer のリスト
    // アドレスを覚えておくだけで、Observer の生成・破棄は行わない
    std::vector<Observer*> observers_{};
};

int main()
{
    ScoreManager scoreManager;

    // Observer 本体は利用する側で用意する
    ScoreUI      scoreUI;
    SoundManager soundManager;

    // Observer のアドレスを登録する
    scoreManager.addObserver(&scoreUI);
    scoreManager.addObserver(&soundManager);

    // スコアが増えると、登録済みの全 Observer に自動で通知される
    scoreManager.addScore(100);

    // 不要になったら個別に解除できる
    scoreManager.removeObserver(&soundManager);
}

