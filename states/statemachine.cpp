//
// Created by 200458668 on 10/28/2021.
//

#include "statemachine.hpp"
#include "logger.hpp"

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

        //logic to remove state
        if(this->_popState && !this->_states.empty()){
            _logger.SendMessage(PRIORITY::INFO, "State Removed");
            this->_states.pop();

            //If stack is not empty after pop resume the next state
            if( !this->_states.empty()){
                this->_states.top()->Resume();
            }

            this->_popState = false;
        }

        //logic to push state
        if( this->_pushState ){
          _logger.SendMessage(PRIORITY::INFO, "State Pushed");
            if ( !this->_states.empty()){
              // replace state
                if(!this->_replaceState){
                  this->_states.pop();
                }

                //top state is paused if adding without replacing
                else{
                  this->_states.top()->Pause();
                }
            }

            this->_states.push( std::move( this->_state ));
            this->_states.top()->Init();
            this->_pushState = false;
        }
    }

    StatePtr &StateMachine::GetActiveState() {
      return this->_states.top();
    }
}
