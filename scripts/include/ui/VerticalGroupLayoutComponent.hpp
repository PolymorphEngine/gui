/*
** EPITECH PROJECT, 2020
** VerticalGroupLayoutScript
** File description:
** header for VerticalGroupLayoutDebug.cpp
*/

#pragma once

#include "polymorph/engine/core.hpp"
#include "polymorph/engine/render-2D.hpp"

namespace polymorph::engine::gui
{
    class VerticalGroupLayoutComponent;
    using VerticalGroupLayout = safe_ptr<VerticalGroupLayoutComponent>;
    
    class VerticalGroupLayoutComponent : public AComponent
    {
        public:
            VerticalGroupLayoutComponent(GameObject entity, std::shared_ptr<myxmlpp::Node> data)
            : AComponent(data, entity){};
            // Here add properties you want to initialize with configuration values in the initializer
            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            render2D::SpriteRenderer ViewPort;
            bool ScaleViewPortHeight;

            float Spacing;
            float LeftPadding;
            float RightPadding;
            float TopPadding;
            float DownPadding;

            bool ControlChildWidth;
            bool ControlChildHeight;
            // Here add properties you want to initialize with configuration values in the initializer

        private:

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:

        private:

            //////////////////////--------------------------/////////////////////////

    };
}