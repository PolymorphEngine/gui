/*
** EPITECH PROJECT, 2020
** VerticalGroupLayoutScript.cpp
** File description:
** VerticalGroupLayoutScript implementation
*/

#include "ui/VerticalGroupLayoutImpl.hpp"

namespace polymorph::engine::gui
{

    // Called only once when the Script is enabled the first time
    void VerticalGroupLayoutImpl::start()
    {

    }

    // Called every frame by the engine
    void VerticalGroupLayoutImpl::update()
    {
        auto viewPortPos = transform->getPosition();
        engine::Rect viewPortSize;
        if (!!ViewPort)
            viewPortSize = ViewPort->sprite->getCrop();
        auto nbChildren = static_cast<float>(transform->nbChildren());
        auto actualHeight = TopPadding;
        for (auto &child : **transform)
        {
            if (!child->gameObject->isActive())
            {
                nbChildren --;
                continue;
            }
        }
        for (auto &child : **transform)
        {
            if (!child->gameObject->isActive())
                continue;
            auto pos = engine::Vector3(viewPortPos.x + LeftPadding, viewPortPos.y + actualHeight, 0);
            child->transform->setPosition(pos);
            auto renderer = child->getComponent<render2D::SpriteRendererComponent>();
            float height = 0.0f;
            if (!!renderer && renderer->sprite)
            {
                engine::Vector2 scale = renderer->sprite->scale;
                auto actual = renderer->sprite->getCrop();
                if (ControlChildWidth && !!ViewPort)
                    scale.x = ((viewPortSize.x - LeftPadding) - RightPadding) / actual.width;
                if (ControlChildHeight && !!ViewPort) //TODO: check maths
                    scale.y = ((viewPortSize.y /
                    nbChildren) + TopPadding + DownPadding + (nbChildren * Spacing)) / actual.height;
                if (ControlChildHeight || ControlChildWidth)
                    renderer->sprite->setScale(scale);
                height = actual.height * scale.y;
                //height = renderer->sprite->getSize().y;
                //child->setScale(scale);
            }
            actualHeight += height + Spacing;
        }
        actualHeight += DownPadding;
        if (ScaleViewPortHeight) {
            engine::Vector2 scale = {1, actualHeight / viewPortSize.height};
            ViewPort->sprite->setScale(scale);
        }
    }

    void VerticalGroupLayoutImpl::build()
    {
        _setProperty("TopPadding", TopPadding);
        _setProperty("DownPadding", DownPadding);
        _setProperty("LeftPadding", LeftPadding);
        _setProperty("RightPadding", RightPadding);
        _setProperty("Spacing", Spacing);
        _setProperty("ControlChildWidth", ControlChildWidth);
        _setProperty("ControlChildHeight", ControlChildHeight);
        _setProperty("ScaleViewPortHeight", ScaleViewPortHeight);
        _setProperty("ViewPort", ViewPort);
    }

    void VerticalGroupLayoutImpl::saveAll()
    {
        saveProperty("TopPadding", TopPadding);
        saveProperty("DownPadding", DownPadding);
        saveProperty("LeftPadding", LeftPadding);
        saveProperty("RightPadding", RightPadding);
        saveProperty("Spacing", Spacing);
        saveProperty("ControlChildWidth", ControlChildWidth);
        saveProperty("ControlChildHeight", ControlChildHeight);
        saveProperty("ScaleViewPortHeight", ScaleViewPortHeight);
        saveProperty("ViewPort", ViewPort);
    }

}