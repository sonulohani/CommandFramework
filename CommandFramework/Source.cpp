#include "UndoCommand.h"
#include "BasicCommand.h"
#include <iostream>

using namespace CommandFramework;

class ABC {
public:
	void foo()
	{
		std::cout << "Foo";
	}

	void bar()
	{
	std::cout << "bar";
	}

	int sum(int a, int b)
	{
		std::cout << a + b;
	}
};

int main() {
	ABC a;
	BasicCommand<> *pBasicCommand = new BasicCommand<>(std::bind(&ABC::foo, std::ref(a)));
	BasicCommand<> *pBasicCommand1 = new BasicCommand<>(std::bind(&ABC::bar, std::ref(a)));
	BasicCommand<int, int, int> *pSumCommand = new BasicCommand<int, int, int>(std::bind(&ABC::sum, std::ref(a), 5, 6));
	UndoCommand<> *pUndoCommand = new UndoCommand<>();
	pUndoCommand->pushCommand(pBasicCommand);
	pUndoCommand->pushCommand(pBasicCommand1);
	pUndoCommand->pushCommand(pSumCommand);
	pUndoCommand->undo();
	pUndoCommand->undo();

	return 0;
}