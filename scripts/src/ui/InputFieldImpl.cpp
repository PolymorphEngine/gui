/*
** EPITECH PROJECT, 2020
** InputFieldScript.cpp
** File description:
** InputFieldScript implementation
*/

#include "IInputFieldHandler.hpp"
#include "ui/InputFieldImpl.hpp"

namespace polymorph::gui
{
    InputFieldImpl::InputFieldImpl(engine::GameObject gameObject)
            : InputFieldComponent(gameObject)
    {}

    // Called only once when the Script is enabled the first time
    void InputFieldImpl::start()
    {
        _focusedTextTimer = std::make_unique<engine::Timer>(Game, 0.5f);
    }

    // Called every frame by the engine
    void InputFieldImpl::update()
    {
        _focusedTextTimer->tick();
        if (_isFocused)
            _updateFocus();
        
    }

    void InputFieldImpl::_updateFocus()
    {
        if (_focusedTextTimer->timeIsUp()) {
            if (_isShowingFocusedText) {
                _removeFocus();
                _isShowingFocusedText = false;
            } else {
                _addFocus();
                _isShowingFocusedText = true;
            }
        }
    }

    void InputFieldImpl::onKeyPressed(event::KeyCode code)
    {
        if (!_isFocused || code == event::KeyCode::NONE) return;
        if (code == event::KeyCode::ENTER) {
            _isFocused = false;
            if (!!OnSubmit) {
                auto handler = OnSubmit->getComponent<IInputFieldHandler>();
                if (!!handler)
                    handler->onSubmit(Target->text->getString());
            }
        }
        else if (code == event::KeyCode::BACKSPACE or code == event::KeyCode::DEL)
                _delete();
        else {
            auto input = event::input::getKeyChar(code);
            if (input == 'q')
                input = 'a';
            else if (input == 'w')
                input = 'z';
            else if (input == 'a')
                input = 'q';
            else if (input == 'z')
                input = 'w';
            if (isShiftDown && (input >= 'a' && input <= 'z'))
                input = static_cast<char>(std::toupper(static_cast<int>(input)));
            if (input == ',' && isShiftDown)
                input = '.';
            if ((Type == InputFieldType::Text_Only && (input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
            || (Type == InputFieldType::Numbers_Only && (input >= '0' && input <= '9'))
            || (Type == InputFieldType::AlphaNumeric && input != '\0'))
                _updateText(input);
        }
        if (!!OnValueChanged) {
            auto handler = OnValueChanged->getComponent<IInputFieldHandler>();
            if (!!handler)
                handler->onValueChanged(Target->text->getString());
        }
    }

    void InputFieldImpl::onMouseButtonPressed(event::MouseEvent &button)
    {

        if (button.button == event::MouseButton::LEFT_BUTTON) {
            auto rect = PlaceHolder->sprite->getCrop();
            auto pos = PlaceHolder->transform->getPosition();
            auto mouse_pos = button.position;
            rect.x = pos.x + Target->offset.x;
            rect.y = pos.y + Target->offset.y;
            rect.width = PlaceHolder->sprite->getTextureWidth();
            rect.height = PlaceHolder->sprite->getTextureHeight();
            if (rect.contains(mouse_pos))
                _focusText();
            else
                _unfocusText();
        }
    }

    void InputFieldImpl::onKeyDown(event::KeyCode code)
    {
        if (code == event::KeyCode::LEFT_SHIFT || code == event::KeyCode::RIGHT_SHIFT)
            isShiftDown = true;
        else
            isShiftDown = false;
    }

    void InputFieldImpl::_updateText(char text)
    {
        _actualText = Target->text->getString();
        if (_isShowingFocusedText)
            _removeFocus();
        Target->text->setString(_actualText + text);
        if (_isShowingFocusedText)
            _addFocus();
    }

    void InputFieldImpl::_delete()
    {
        _actualText = Target->text->getString();
        if (_isShowingFocusedText)
            _removeFocus();
        if(!_actualText.empty())
            Target->text->setString(_actualText.substr(0, _actualText.size() - 1));
        if (_isShowingFocusedText)
            _addFocus();
    }

    void InputFieldImpl::_focusText()
    {
        if (!_isFocused) {
            _addFocus();
            _isFocused = true;
            _isShowingFocusedText = true;
        }
    }

    void InputFieldImpl::_unfocusText()
    {
        if (_isFocused)
        {
            if (!!OnExitFocus) {
                auto handler = OnExitFocus->getComponent<IInputFieldHandler>();
                if (!!handler)
                    handler->onExitFocus(Target->text->getString());
            }
            if (_isShowingFocusedText)
                _removeFocus();
        }
        _isFocused = false;
        _isShowingFocusedText = false;
    }

    void InputFieldImpl::_addFocus()
    {
        _actualText = Target->text->getString() + '|';
        Target->text->setString(_actualText);
    }

    void InputFieldImpl::_removeFocus()
    {
        _actualText = Target->text->getString().substr(0, Target->text->getString().size() - 1);
        Target->text->setString(_actualText);
    }

}