/*
** EPITECH PROJECT, 2020
** ScrollRectImpl
** File description:
** header for ScrollRect.c
*/



#include <polymorph/engine/types.hpp>
#include <polymorph/engine/core.hpp>
#include "ui//ScrollRectImpl.hpp"

namespace polymorph::engine::gui
{
    void ScrollRectImpl::update()
    {

    }

    void ScrollRectImpl::start()
    {
        if (ScrollSpeed == 0)
            ScrollSpeed = 1.0f;
    }

    void ScrollRectImpl::onMouseEvent(event::MouseEvent &event)
    {
        if (event.inputType != event::InputType::SCROLL)
            return;
        if (ScrollingChildren)
            for (auto &child: **ContentRect)
            {
                child->setPosition(child->getPosition() + engine::Vector3(0, event.moved * ScrollSpeed, 0));
                if (child->getPosition().y < RectTop || child->getPosition().y > RectBottom)
                    child->gameObject->setActive(false);
                else
                    child->gameObject->setActive(true);
            }
        else
        {
            ContentRect->setPositionY(ContentRect->getPosition().y + (event.moved * ScrollSpeed));
            for (auto &child: **ContentRect)
            {
                if (child->getPosition().y < RectTop || child->getPosition().y > RectBottom)
                    child->gameObject->setActive(false);
                else
                    child->gameObject->setActive(true);
            }
        }

    }

    void ScrollRectImpl::addChild(polymorph::engine::GameObject child)
    {
        child->transform->setParent(ContentRect);
    }

    void ScrollRectImpl::removeChild(polymorph::engine::GameObject child)
    {
        ContentRect->removeChild(child->transform);
    }
}

void polymorph::engine::gui::ScrollRectImpl::build()
{
    _setProperty("ScrollSpeed", ScrollSpeed);
    _setProperty("RectTop", RectTop);
    _setProperty("RectBottom", RectBottom);
    _setProperty("ScrollingChildren", ScrollingChildren);
    _setProperty("ContentRect", ContentRect);
}

void polymorph::engine::gui::ScrollRectImpl::saveAll()
{
    saveProperty("ScrollSpeed", ScrollSpeed);
    saveProperty("RectTop", RectTop);
    saveProperty("RectBottom", RectBottom);
    saveProperty("ScrollingChildren", ScrollingChildren);
    saveProperty("ContentRect", ContentRect);
}
