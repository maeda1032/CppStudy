
#include <iostream>
#include <mutex>
#include <thread>

struct Account
{
	int id;// 口座番号
	int balance;//残高
	std::mutex mtx;//ミューテックス
};

void transfer(Account& from, Account& to, int amount)
{
	for (int i = 0; i < 10000; ++i)
	{
		from.mtx.lock();
		to.mtx.lock();
		from.balance -= amount;
		to.balance += amount;
		from.mtx.unlock();
		to.mtx.unlock();
	}
}

int main()
{
	Account bankA{1,10000 };
	Account bankB{2,10000 };

	std::thread tA(transfer,bankA,bankB,1);
	std::thread tB(transfer,bankB,bankA,1);

	// 両スレッドの終了を待つ
	tA.join();
	tB.join();

	return 0;

}

