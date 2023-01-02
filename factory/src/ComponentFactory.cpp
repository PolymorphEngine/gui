/*
** EPITECH PROJECT, 2022
** ComponentFactory.cpp
** File description:
** ComponentFactory.cpp
*/

#include "ComponentFactory.hpp"
#include "ui/ButtonImpl.hpp"
#include "ui/ScrollRectImpl.hpp"
#include "ui/VerticalGroupLayoutImpl.hpp"
#include "ui/HorizontalGroupLayoutImpl.hpp"
#include "ui/InputFieldImpl.hpp"
#include "ui/CanvasImpl.hpp"

polymorph::engine::api::ComponentFactory::ComponentFactory() : AComponentFactory()
{
}

void polymorph::engine::api::ComponentFactory::_registerBuildables(
        std::unordered_map<std::string, polymorph::engine::api::AComponentFactory::FactoryLambda> &buildables)
{
    buildables.emplace("Button", make<gui::ButtonImpl>());
    buildables.emplace("ScrollRect", make<gui::ScrollRectImpl>());
    buildables.emplace("VerticalGroupLayout", make<gui::VerticalGroupLayoutImpl>());
    buildables.emplace("HorizontalGroupLayout", make<gui::HorizontalGroupLayoutImpl>());
    buildables.emplace("InputField", make<gui::InputFieldImpl>());
    buildables.emplace("Canvas", make<gui::CanvasImpl>());
}