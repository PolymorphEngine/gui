/*
** EPITECH PROJECT, 2020
** ButtonScript
** File description:
** header for ButtonDebug.cpp
*/

#pragma once

#include <utility>

#include "polymorph/engine/core.hpp"
#include "polymorph/engine/render-2D.hpp"
#include "polymorph/engine/input.hpp"

namespace polymorph::engine::gui
{
    class ButtonComponent : public AComponent
    {
        public:
            ButtonComponent(GameObject entity, std::shared_ptr<myxmlpp::Node> data)
            : AComponent(data, entity){};

            ///////////////////////////// PROPERTIES ////////////////////////////////

        public:
            void onMouseEvent(event::MouseEvent &event) override = 0;

            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            render2D::SpriteRenderer Target;
            render2D::TextureModule HoverTexture;
            render2D::TextureModule ClickTexture;
            engine::GameObject onClickHandler;
            engine::GameObject onReleaseHandler;
            engine::GameObject onHoldHandler;
            //////////////////////--------------------------/////////////////////////
    };
}