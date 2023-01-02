/*
** EPITECH PROJECT, 2020
** CanvasScript
** File description:
** header for CanvasDebug.cpp
*/

#pragma once

#include "polymorph/engine/core.hpp"
#include "polymorph/engine/render-core.hpp"

namespace polymorph::engine::gui
{
    class CanvasComponent;
    using Canvas = safe_ptr<CanvasComponent>;
    
    class CanvasComponent : public AComponent
    {
        public:
            CanvasComponent(GameObject entity, std::shared_ptr<myxmlpp::Node> data)
            : AComponent(data, entity){};
            render::Camera Target;
            // Here add properties you want to initialize with configuration values in the initializer

        private:

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:

        private:

            //////////////////////--------------------------/////////////////////////

    };
}