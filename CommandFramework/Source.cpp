#include "BasicCommand.h"
#include "UndoCommand.h"
#include "UndoRedoCommand.h"
#include <iostream>

using namespace CommandFramework;

class ABC {
public:
  void foo() { std::cout << "Foo"; }

  void bar() { std::cout << "bar"; }

  int sum(int a, int b) {
    std::cout << a + b;
    return a + b;
  }
};

int main() {
  ABC a;
  BasicCommand<> *pBasicCommand =
      new BasicCommand<>(std::bind(&ABC::foo, std::ref(a)));
  BasicCommand<> *pBasicCommand1 =
      new BasicCommand<>(std::bind(&ABC::bar, std::ref(a)));
  auto func = std::bind(&ABC::sum, std::ref(a), 5, 6);
  BasicCommand<decltype(func)> *pSumCommand =
      new BasicCommand<decltype(func)>(func);
  UndoCommand *pUndoCommand = new UndoCommand();
  pUndoCommand->pushCommand(pBasicCommand);
  pUndoCommand->pushCommand(pBasicCommand1);
  pUndoCommand->pushCommand(pSumCommand);
  pBasicCommand->execute();
  try {
    pBasicCommand1->execute();
  } catch (NotImplementedException e) {
    std::cout << e.what();
  }
  pSumCommand->execute();
  pUndoCommand->undo();
  pUndoCommand->undo();
  pUndoCommand->undo();

  return 0;
}