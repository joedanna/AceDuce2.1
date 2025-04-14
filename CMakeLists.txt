cmake_minimum_required(VERSION 3.29)
project(AceDuce2_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(AceDuce2_1 main.cpp
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        AbstractBet.cpp
        AbstractBet.h
        Bet.cpp
        Bet.h
        Game.cpp
        Game.h
        Pot.cpp
        Pot.h
        Player.cpp
        Player.h
        MultiGame.cpp
        MultiGame.h)
