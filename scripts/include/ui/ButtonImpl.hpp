/*
** EPITECH PROJECT, 2020
** ButtonScript
** File description:
** header for ButtonDebug.cpp
*/

#pragma once

#include "polymorph/Core.hpp"
#include "ui/ButtonComponent.hpp"

namespace polymorph::gui
{

    COMPONENT_IMPL(polymorph::gui,  Button)
    {
        COMPONENT_IMPL_CTOR(Button)
            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            // Here add properties you want to initialize with configuration values in the initializer

        private:
            render2D::TextureModule _defaultTexture;

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void update() override;

            void onMouseEvent(event::MouseEvent &event) override;

        private:

            //////////////////////--------------------------/////////////////////////

    };
}
MAKE_INITIALIZER(polymorph::gui, Button)