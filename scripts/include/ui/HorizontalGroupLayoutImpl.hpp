/*
** EPITECH PROJECT, 2020
** HorizontalGroupLayoutScript
** File description:
** header for HorizontalGroupLayoutDebug.cpp
*/

#pragma once

#include "polymorph/Core.hpp"
#include "polymorph/render-2D.hpp"
#include "ui/HorizontalGroupLayoutComponent.hpp"

namespace polymorph::gui
{

    COMPONENT_IMPL(gui, HorizontalGroupLayout)
    {
        COMPONENT_IMPL_CTOR(HorizontalGroupLayout)
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
MAKE_INITIALIZER(polymorph::gui, HorizontalGroupLayout)