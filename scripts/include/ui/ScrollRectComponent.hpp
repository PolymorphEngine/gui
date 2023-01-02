/*
** EPITECH PROJECT, 2020
** ScrollRectComponent
** File description:
** header for ScrollRect.c
*/


#pragma once

#include <polymorph/engine/types.hpp>
#include <polymorph/engine/core.hpp>
#include <polymorph/engine/api.hpp>
#include "polymorph/engine/input/mouse.hpp"

namespace polymorph::engine::gui
{
    class ScrollRectComponent;
    using ScrollRect = safe_ptr<ScrollRectComponent>;

    class ScrollRectComponent : public AComponent, public event::IMouseHandler
    {
        public:
            ScrollRectComponent(GameObject entity, std::shared_ptr<myxmlpp::Node> data)
            : AComponent(data, entity){};
            // Here add properties you want to initialize with configuration values in the initializer
            //////////////////////--------------------------/////////////////////////


            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            engine::Transform ContentRect;
            float ScrollSpeed = 1.0f;
            float RectTop = 0;
            float RectBottom = 0;
            bool ScrollingChildren = true;


        protected:

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override = 0;

            void update() override = 0;
            virtual void addChild(polymorph::engine::GameObject child) = 0;
            virtual void removeChild(polymorph::engine::GameObject child) = 0;

        protected:

            //////////////////////--------------------------/////////////////////////

    };
}

