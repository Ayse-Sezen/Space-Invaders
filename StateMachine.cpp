#include "StateMachine.h"

void StateMachine::AddState(StatePtr newState, bool isReplacingFlag) {
	// Prepare to add states by setting proper flags...
	this->isAdding = true;
	this->isReplacing = isReplacingFlag;

	// ... and moving requested new state into newState
	this->newState = std::move(newState);
}

void StateMachine::RemoveState() {
	// Prepare to remove states by setting flag
	this->isRemoving = true;
}

// Handles the state changes
void StateMachine::ProcessStateChanges() {
	// if you are removaing a state and the stack is not empty...
	if (this->isRemoving && !this->stateMachine.empty()) {
		// Pop the state
		// We check to see if stack was empty 
		// so we're not popping from an empty stack
		this->stateMachine.pop();

		// if stack is not empty after pop...
		if (!this->stateMachine.empty()) {
			// resume game with current state
			this->stateMachine.top()->Resume();
		}

		// done removing a state
		this->isRemoving = false;
	}
	
	// if you are adding a state...
	if (this->isAdding) {
		// and the stack is not empty...
		if (!this->stateMachine.empty()) {
			// if you are replacing a state...
			if (this->isReplacing) {
				// pop the current state off the stack
				this->stateMachine.pop();
			}
			else {
				// if you are not replacing the
				// current state but just adding on to it,
				// then simply pause the current state
				this->stateMachine.top()->Pause();
			}
		}

		// push the new state onto the stack
		this->stateMachine.push(std::move(this->newState));
		
		// initialize the new state by calling state's init function
		this->stateMachine.top()->Init();

		// done adding new state
		this->isAdding = false;
	}
}

StatePtr &StateMachine::GetActiveState() {
	// return the current state game is in
	return this->stateMachine.top();
}