/*
** EPITECH PROJECT, 2020
** ScrollRectImpl
** File description:
** header for ScrollRect.c
*/

#pragma once

#include "ui/ScrollRectComponent.hpp"

namespace polymorph::gui
{
    COMPONENT_IMPL(polymorph::gui, ScrollRect)
    {
        COMPONENT_IMPL_CTOR(ScrollRect)

            void onMouseEvent(event::MouseEvent &event) override;
            /////////////////////////////// METHODS /////////////////////////////////
        public:
    
        void start() override;
    
        void update() override;
        
        void addChild(polymorph::engine::GameObject child) final;
        void removeChild(polymorph::engine::GameObject child) final;
    
        private:
    
        //////////////////////--------------------------/////////////////////////
    
    };
}

MAKE_INITIALIZER(polymorph::gui, ScrollRect)