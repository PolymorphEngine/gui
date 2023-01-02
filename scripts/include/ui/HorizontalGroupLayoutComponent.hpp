/*
** EPITECH PROJECT, 2020
** HorizontalGroupLayoutScript
** File description:
** header for HorizontalGroupLayoutDebug.cpp
*/

#pragma once

#include "polymorph/engine/core.hpp"
#include "polymorph/engine/render-2D.hpp"

namespace polymorph::engine::gui
{
    class HorizontalGroupLayoutComponent;
    using HorizontalGroupLayout = safe_ptr<HorizontalGroupLayoutComponent>;
    class HorizontalGroupLayoutComponent : public AComponent
    {
        public:
            HorizontalGroupLayoutComponent(GameObject entity, std::shared_ptr<myxmlpp::Node> data): AComponent(data, entity){};
            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            render2D::SpriteRenderer ViewPort;
            bool ScaleViewPortWidth;

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