//
// Created by 200458668 on 10/28/2021.
//

#include "statemachine.hpp"

namespace IE{
    void StateMachine::PushState( StatePtr state, bool replaceState ) {
        this->_pushState = true;
        this->_replaceState = replaceState;
        this->_state = std::move (state);
    }

    void StateMachine::PopState(){
        this->_popState = true;
    }

    void StateMachine::ProcessStack() {
        if(this->_pushState && !this->_states.empty()){
            this->_states.pop();

            //If stack is not empty after pop resume the next state
            if( !this->_states.empty()){
                this->_states.top()->Resume();
            }

            this->_popState = false;
        }

        if( this->_pushState ){
            if ( !this->_states.empty()){
                this->_states.pop();
            }

            else{
                this->_states.top()->Pause();
            }

            this->_states.push( std::move( this->_state ));
            this->_states.top()->Init();
            this->_pushState = false;
        }
    }

    StatePtr &StateMachine::GetActiveState() {return this->_states.top();}
}
