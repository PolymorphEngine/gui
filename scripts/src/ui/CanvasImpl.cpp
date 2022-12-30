/*
** EPITECH PROJECT, 2020
** CanvasScript.cpp
** File description:
** CanvasScript implementation
*/

#include "ui/CanvasImpl.hpp"

namespace polymorph::gui
{
    CanvasImpl::CanvasImpl(engine::GameObject gameObject)
            : CanvasComponent(gameObject)
    {}

    // Called only once when the Script is enabled the first time
    void CanvasImpl::start()
    {
    }

    // Called every frame by the engine
    void CanvasImpl::update()
    {

    }

}