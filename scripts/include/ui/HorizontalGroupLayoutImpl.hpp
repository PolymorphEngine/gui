/*
** EPITECH PROJECT, 2020
** HorizontalGroupLayoutScript
** File description:
** header for HorizontalGroupLayoutDebug.cpp
*/

#pragma once

#include "polymorph/engine/core.hpp"
#include "polymorph/engine/render-2D.hpp"
#include "ui/HorizontalGroupLayoutComponent.hpp"

namespace polymorph::engine::gui
{
    class HorizontalGroupLayoutImpl : public HorizontalGroupLayoutComponent
    {
        public:
            //////////////////////--------------------------/////////////////////////
            HorizontalGroupLayoutImpl(GameObject entity, std::shared_ptr<myxmlpp::Node> data)
            : HorizontalGroupLayoutComponent(entity, data){};
            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////

        private:

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
