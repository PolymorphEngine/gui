/*
** EPITECH PROJECT, 2020
** ScrollRectImpl
** File description:
** header for ScrollRect.c
*/



#include <polymorph/Types.hpp>
#include <polymorph/Core.hpp>
#include "ui//ScrollRectImpl.hpp"
#include "../../Factory/include/ScriptFactory.hpp"

namespace polymorph::gui
{
    ScrollRectImpl::ScrollRectImpl(polymorph::engine::GameObject gameObject)
            : ScrollRectComponent(std::move(gameObject))
    {
    }

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