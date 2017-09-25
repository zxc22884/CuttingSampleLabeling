#include "CommandManager.h"

CommandManager::CommandManager() 
{

}

CommandManager::~CommandManager()
{
	_undo.clear();
	_redo.clear();
}

void CommandManager::execute(Command* cmd)
{

}

void CommandManager::redo() 
{

}

void CommandManager::undo() 
{

}