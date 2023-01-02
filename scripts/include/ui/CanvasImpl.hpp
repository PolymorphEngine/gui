/*
** EPITECH PROJECT, 2020
** CanvasScript
** File description:
** header for CanvasDebug.cpp
*/

#pragma once

#include "CanvasComponent.hpp"

namespace polymorph::engine::gui
{
    class CanvasImpl : public CanvasComponent
    {
        public:
            CanvasImpl(GameObject entity, std::shared_ptr<myxmlpp::Node> data)
            : CanvasComponent(entity, data){};
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
