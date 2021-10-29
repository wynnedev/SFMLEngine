//
// Created by 200458668 on 10/28/2021.
//

#ifndef SFMLTEST_STATE_HPP
#define SFMLTEST_STATE_HPP

///TODO IMPLEMENT ACTOR PATTERN FOR IN GAME OBJECTS
///TODO Update state class for error handling

namespace IE {
    class State {
    public:
        virtual void Init() = 0;
        virtual void HandleInput() = 0;
        virtual void Update( float deltaTime ) = 0;
        virtual void Draw( float deltaTime ) = 0;

        virtual void Pause() {}
        virtual void Resume() {}

    private:
    };
};


#endif//SFMLTEST_STATE_HPP
