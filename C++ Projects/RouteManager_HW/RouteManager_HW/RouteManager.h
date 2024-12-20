#pragma once

#include "Map.h"


class RouteManager
{
public:
    void addNewRoute(const int& distance, const std::string& name, const std::string& from, const std::string& to);

    void replaceRoute(const int& distance, const std::string& name, const std::string& from, const std::string& to);

    void removeRoute(const int& distance);

    void showFirstRoute() const;

    void showAllRoutes() const;


private:
    Map m_map;
};