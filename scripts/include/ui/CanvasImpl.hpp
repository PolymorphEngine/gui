/*
** EPITECH PROJECT, 2020
** CanvasScript
** File description:
** header for CanvasDebug.cpp
*/

#pragma once

#include "CanvasComponent.hpp"

namespace polymorph::gui
{

    COMPONENT_IMPL(gui, Canvas)
    {
        COMPONENT_IMPL_CTOR(Canvas)
            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////

        private:

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void update() override;

        private:

            //////////////////////--------------------------/////////////////////////

    };
}
MAKE_INITIALIZER(polymorph::gui, Canvas)