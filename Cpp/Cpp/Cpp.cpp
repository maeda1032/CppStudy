
#include <iostream>
#include "Random.h"
#include "Input.h"
#include "Judge.h"
#include "Display.h"
#include "Result.h"


int main()
{
	Random random;
	Input input;
	Judge judge;
	Display display;

	random.Generate();

	while (true)
	{
		//入力値を設定する
		input.Set();

		//判定
		Result res = judge.Compare(random,input);

		//結果を表示する
		display.disp(res);

		//クリアしていたらゲームループを抜ける
		if (res.isClear_)
		{
			break;
		}
	}
}

