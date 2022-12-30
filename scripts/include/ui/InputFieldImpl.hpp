/*
** EPITECH PROJECT, 2020
** InputFieldScript
** File description:
** header for InputFieldDebug.cpp
*/

#pragma once

#include "InputFieldComponent.hpp"
#include "ScriptingAPI/ScriptingApi.hpp"

namespace polymorph::gui
{

    COMPONENT_IMPL(gui, InputField)
    {
        COMPONENT_IMPL_CTOR(InputField)

            void onKeyDown(event::KeyCode code) override;
            //////////////////////--------------------------/////////////////////////


            ///////////////////////////// PROPERTIES ////////////////////////////////
        private:
            bool _isFocused = false;
            std::string _actualText;
            bool _isShowingFocusedText = false;
            std::unique_ptr<engine::Timer> _focusedTextTimer;

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void update() override;

            void onKeyPressed(event::KeyCode code) override;

            void onMouseButtonPressed(event::MouseEvent &button) override;

        private:

            void _updateFocus();
            
            void _updateText(char text);
            
            void _delete();
            
            void _focusText();
            
            void _unfocusText();
            
            void _addFocus();
            void _removeFocus();


            //////////////////////--------------------------/////////////////////////

    };
}
MAKE_INITIALIZER(polymorph::gui, InputField)