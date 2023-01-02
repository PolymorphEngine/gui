/*
** EPITECH PROJECT, 2020
** IInputFieldHandler.hpp
** File description:
** header for IInputFieldHandler.c
*/


#pragma once

#include <string>

namespace polymorph::engine::gui
{
    class IInputFieldHandler
    {
        public:
            virtual void onValueChanged(std::string value) = 0;
    
            virtual void onExitFocus(std::string value) = 0;
    
            virtual void onSubmit(std::string value) = 0;
    };
}
