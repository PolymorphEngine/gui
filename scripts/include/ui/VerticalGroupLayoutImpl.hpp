/*
** EPITECH PROJECT, 2020
** VerticalGroupLayoutScript
** File description:
** header for VerticalGroupLayoutDebug.cpp
*/

#pragma once

#include "ScriptingAPI/ScriptingApi.hpp"
#include "VerticalGroupLayoutComponent.hpp"

namespace polymorph::gui
{

    COMPONENT_IMPL(gui, VerticalGroupLayout)
    {
        COMPONENT_IMPL_CTOR(VerticalGroupLayout)
            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void update() override;

        private:

            //////////////////////--------------------------/////////////////////////

    };
}
MAKE_INITIALIZER(polymorph::gui, VerticalGroupLayout)