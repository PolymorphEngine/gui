/*
** EPITECH PROJECT, 2020
** ButtonScript.cpp
** File description:
** ButtonScript implementation
*/

#include "polymorph/engine/core.hpp"
#include "IButtonHandler.hpp"
#include "ui/ButtonImpl.hpp"

namespace polymorph::engine::gui
{

    // Called only once when the Script is enabled the first time
    void ButtonImpl::start()
    {
        if (!!Target)
            _defaultTexture = Target->sprite;
    }

    // Called every frame by the engine
    void ButtonImpl::update()
    {
    }

    void ButtonImpl::onMouseEvent(event::MouseEvent &event)
    {
        if (!Target || Target->sprite == nullptr || !enabled || !gameObject->isActive())
            return;
        auto rect = Target->sprite->getCrop();
        auto pos = Target->transform->getPosition();
        auto mouse_pos = event.position;
        rect.x = pos.x + Target->offset.x;
        rect.y = pos.y + Target->offset.y;
        rect.width = Target->sprite->getTextureWidth();
        rect.height = Target->sprite->getTextureHeight();

        if (!rect.contains(mouse_pos)) {
            Target->sprite = _defaultTexture;
            return;
        }
        Target->sprite = HoverTexture;
        if (event.inputType == event::InputType::PRESSED)
        {
            Target->sprite = ClickTexture;
            if (!!onClickHandler && onClickHandler->isActive())
            {
                auto handler = onClickHandler->getComponent<IButtonHandler>();
                if (!!handler)
                    handler->onButtonPressed(Target->gameObject);
            }
        }
        if (event.inputType == event::InputType::T_DOWN)
        {
            Target->sprite = ClickTexture;
            if (!!onHoldHandler && onHoldHandler->isActive())
            {
                auto handler = onHoldHandler->getComponent<IButtonHandler>();
                if (!!handler)
                    handler->onButtonDown(Target->gameObject);
            }
        }
        if (Scene.isSceneUnloaded())
            return;
        if (event.inputType == event::InputType::RELEASED)
        {
            Target->sprite = HoverTexture;
            if (!!onReleaseHandler && onReleaseHandler->isActive())
            {
                auto handler = onReleaseHandler->getComponent<IButtonHandler>();
                if (!!handler)
                    handler->onButtonReleased(Target->gameObject);
            }
        }
    }
}

void polymorph::engine::gui::ButtonImpl::build()
{
    _setProperty("Target", Target);
    _setProperty("HoverTexture", HoverTexture);
    _setProperty("ClickTexture", ClickTexture);
    _setProperty("onClickHandler", onClickHandler);
    _setProperty("onHoldHandler", onHoldHandler);
    _setProperty("onReleaseHandler", onReleaseHandler);
}

void polymorph::engine::gui::ButtonImpl::saveAll()
{
    saveProperty("Target", Target);
    saveProperty("HoverTexture", HoverTexture);
    saveProperty("ClickTexture", ClickTexture);
    saveProperty("onClickHandler", onClickHandler);
    saveProperty("onHoldHandler", onHoldHandler);
    saveProperty("onReleaseHandler", onReleaseHandler);
}
