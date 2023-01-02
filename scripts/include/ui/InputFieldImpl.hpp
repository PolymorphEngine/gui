/*
** EPITECH PROJECT, 2020
** InputFieldScript
** File description:
** header for InputFieldDebug.cpp
*/

#pragma once

#include "InputFieldComponent.hpp"

namespace polymorph::engine::gui
{
    class InputFieldImpl : public InputFieldComponent
    {
        public:
            InputFieldImpl(GameObject entity, std::shared_ptr<myxmlpp::Node> data)
            : InputFieldComponent(entity, data){};

            //////////////////////--------------------------/////////////////////////


            ///////////////////////////// PROPERTIES ////////////////////////////////
        private:
            bool _isFocused = false;
            std::string _actualText;
            bool _isShowingFocusedText = false;
            std::unique_ptr<time::Timer> _focusedTextTimer;

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void onKeyDown(event::KeyCode code) override;

            void build() override;

            void saveAll() override;

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
