#ifndef HISTORY_H_
#define HISTORY_H_

#include <vector>
#include "Command.h"


class CommandManager {
private:
	std::vector<Command> _undo;
	std::vector<Command> _redo;

public:
	CommandManager();
	~CommandManager();
	void execute(Command* c);
	void redo();
	void undo();
};

#endif /* HISTORY_H_ */
