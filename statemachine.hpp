//
// Created by 200458668 on 10/28/2021.
//

#ifndef SFMLTEST_STATEMACHINE_HPP
#define SFMLTEST_STATEMACHINE_HPP

#include <memory>
#include <stack>
#include "state.hpp"

namespace IE {
    typedef std::unique_ptr<State> StatePtr;
    class StateMachine {
    public:
        StateMachine(){};
        ~StateMachine(){};
        void PushState( StatePtr state, bool replaceState = true );
        void PopState();
        void ProcessStack();

        StatePtr &GetActiveState();

    private:
        std::stack<StatePtr> _states;
        StatePtr _state;
        bool _replaceState;
        bool _popState;
        bool _pushState;
    };
}


#endif//SFMLTEST_STATEMACHINE_HPP
