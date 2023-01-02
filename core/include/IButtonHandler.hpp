/*
** EPITECH PROJECT, 2020
** IButtonHandler.hpp
** File description:
** header for IButtonHandler.c
*/


#pragma once
#include "polymorph/engine/core.hpp"

namespace polymorph::engine
{
    class Entity;

    using GameObject = safe_ptr<Entity>;
}

namespace polymorph::engine::gui
{
    class IButtonHandler
    {
        public:
            virtual void onButtonPressed(engine::GameObject pressed) = 0;

            virtual void onButtonReleased(engine::GameObject released) = 0;

            virtual void onButtonDown(engine::GameObject pressed) = 0;
    };
}
