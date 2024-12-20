#include "RouteManager.h"


void RouteManager::addNewRoute(const int& distance, const std::string& name, const std::string& from, const std::string& to)
{
    try
    {
        if (distance > 0)
        {
            m_map.insert(distance, name, from, to, 1);
        }
        else
        {
            std::cout << "Distance can't be 0 or less!" << std::endl;
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Error! " << e.what() << std::endl;
    }
}

void RouteManager::replaceRoute(const int& distance, const std::string& name, const std::string& from, const std::string& to)
{
    try
    {
        if (!m_map.isEmpty())
        {
            m_map.insert(distance, name, from, to, 2);
        }
        else
        {
            std::cout << "No routes available." << std::endl;
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Error! " << e.what() << std::endl;
    }
}

void RouteManager::removeRoute(const int& distance)
{
    try
    {
        if (!m_map.isEmpty())
        {
            m_map.remove(distance);
        }
        else
        {
            std::cout << "No routes available." << std::endl;
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Error! " << e.what() << std::endl;
    }
}

void RouteManager::showFirstRoute() const
{
    if (!m_map.isEmpty())
    {
        auto it = m_map.begin();
        std::cout << "Name: " << (*it).getName()
            << ", Distance: " << (*it).getDistance()
            << ", From: " << (*it).getFrom()
            << ", To: " << (*it).getTo() << std::endl;
    }
    else
    {
        std::cout << "No routes available." << std::endl;
    }
}

void RouteManager::showAllRoutes() const
{
    if (!m_map.isEmpty())
    {
        std::cout << "All routes:" << std::endl;
        for (auto it = m_map.begin(); it != m_map.end(); ++it)
        {
            std::cout << "Name: " << (*it).getName()
                      << ", Distance: " << (*it).getDistance()
                      << ", From: " << (*it).getFrom()
                      << ", To: " << (*it).getTo() << std::endl;
        }
    }
    else
    {
        std::cout << "No routes available." << std::endl;
    }
}