/*
** EPITECH PROJECT, 2020
** VerticalGroupLayoutScript
** File description:
** header for VerticalGroupLayoutDebug.cpp
*/

#pragma once

#include "VerticalGroupLayoutComponent.hpp"

namespace polymorph::engine::gui
{
    class VerticalGroupLayoutImpl : public VerticalGroupLayoutComponent
    {
        public:
            VerticalGroupLayoutImpl(polymorph::engine::GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
            : VerticalGroupLayoutComponent(gameObject, node) {};
            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void build() override;

            void saveAll() override;

            void update() override;

        private:

            //////////////////////--------------------------/////////////////////////

    };
}
