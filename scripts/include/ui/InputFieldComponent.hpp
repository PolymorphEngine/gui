/*
** EPITECH PROJECT, 2020
** InputFieldScript
** File description:
** header for InputFieldDebug.cpp
*/

#pragma once

#include "polymorph/engine/core.hpp"
#include "polymorph/engine/render-2D.hpp"
#include "polymorph/engine/input.hpp"

namespace polymorph::engine::gui
{
    class InputFieldComponent : public AComponent, public event::IKeyPressedHandler, public event::IKeyDownHandler, public event::IMouseButtonPressedHandler
    {
        public:
            InputFieldComponent(GameObject entity, std::shared_ptr<myxmlpp::Node> data)
            : AComponent(data, entity){};
            //////////////////////--------------------------/////////////////////////


            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            enum InputFieldType : int
            {
                AlphaNumeric,
                Text_Only,
                Numbers_Only
            };
            // Here add properties you want to initialize with configuration values in the initializer
            render2D::SpriteRenderer PlaceHolder;
            render2D::TextRenderer Target;
            
            bool isShiftDown = false;
            InputFieldType Type;
            engine::GameObject OnSubmit;
            engine::GameObject OnValueChanged;
            engine::GameObject OnExitFocus;

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:


            //////////////////////--------------------------/////////////////////////

    };
}