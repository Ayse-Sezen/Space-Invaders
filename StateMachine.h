#pragma once

#include <memory>
#include <stack>
#include "State.h"

typedef std::unique_ptr<State> StatePtr;

class StateMachine {
public:
	StateMachine() {};
	~StateMachine() {};

	void AddState(StatePtr newState, bool isReplacing = true);
	void RemoveState();
	void ProcessStateChanges();

	// Returns current state at the top of the stack
	StatePtr &GetActiveState();

private:
	// stack of unique ptrs to states
	std::stack<StatePtr> stateMachine;
	StatePtr newState;

	bool isRemoving;
	bool isAdding;
	bool isReplacing;
};