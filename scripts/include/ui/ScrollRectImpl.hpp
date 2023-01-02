/*
** EPITECH PROJECT, 2020
** ScrollRectImpl
** File description:
** header for ScrollRect.c
*/

#pragma once

#include "ui/ScrollRectComponent.hpp"

namespace polymorph::engine::gui
{
    class ScrollRectImpl : public ScrollRectComponent
    {
        public:
            ScrollRectImpl(polymorph::engine::GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
            : ScrollRectComponent(gameObject, node) {};

/////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void build() override;

            void saveAll() override;

            void update() override;
    
            void onMouseEvent(event::MouseEvent &event) override;
            void addChild(polymorph::engine::GameObject child) final;
            void removeChild(polymorph::engine::GameObject child) final;
        
        private:
    
    //////////////////////--------------------------/////////////////////////
    
    };
}
