/*
** EPITECH PROJECT, 2020
** ButtonScript
** File description:
** header for ButtonDebug.cpp
*/

#pragma once

#include "polymorph/engine/core.hpp"
#include "polymorph/engine/api.hpp"
#include "polymorph/engine/config.hpp"
#include "ui/ButtonComponent.hpp"

namespace polymorph::engine::gui
{
    class ButtonImpl : public ButtonComponent
    {
        public:
            ButtonImpl(GameObject entity, std::shared_ptr<myxmlpp::Node> data)
            : ButtonComponent(entity, data) {};

///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            // Here add properties you want to initialize with configuration values in the initializer

        private:
            render2D::Texture _defaultTexture;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void onAwake() override;

            void build() override;

            void saveAll() override;

            void update() override;

            void onMouseEvent(event::MouseEvent &event) override;

        private:

            //////////////////////--------------------------/////////////////////////

    };
}
