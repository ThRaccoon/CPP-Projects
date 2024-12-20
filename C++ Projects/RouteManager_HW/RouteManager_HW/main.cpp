#include <iostream>

#include "RouteManager.h"


// Question answer:
// If we want the sorting order to be descending, not ascending
// we should not use "Min priority queue", but we should use
// "Max priority queue" or in other words we should change
// line 52 in the PriorityQueue.h file from >= to <=.

// Explanation of the 5 functions:
// 1. addNewRoute: Adds a new route (distance cannot be 0 or less).
// 2. replaceRoute: Replaces a route by distance (distance is unique).
// 3. removeRoute: Removes a route by distance (distance is unique).
// 4. showFirstRoute: Displays the route with the smallest distance.
// 5. showAllRoutes: Displays all routes in the map.
//
// !!! The functions addNewRoute and replaceRoute use the same underlying 
// functions insert (from Map.h) and insertElement (from PriorityQueue.h), 
// but with a slight modification called 'mode' to check whether the operation 
// is an addition or a replacement !!!
//
// !!! Distance is unique !!!


int main()
{
    RouteManager rm;

    // Testing replaceRoute, removeRoute, showFirstRoute, and showAllRoutes
    // with an empty map:
    std::cout << "Testing functions with an empty map:" << std::endl;

    std::cout << "Trying to replace a route:" << std::endl;
    rm.replaceRoute(5, "R1", "A", "B");

    std::cout << "Trying to remove a route:" << std::endl;
    rm.removeRoute(5);

    std::cout << "Trying to show the first route:" << std::endl;
    rm.showFirstRoute();

    std::cout << "Trying to show all routes:" << std::endl;
    rm.showAllRoutes();
    //==================================================================================

    std::cout << std::endl;
    // Testing adding two routes and checking if the map sorts them by distance:
    std::cout << "Adding two routes to check if the map sorts them by distance:" << std::endl;
    std::cout << "First route: Distance = 10, Name = R1, From = A, To = B" << std::endl;
    std::cout << "Second route: Distance = 5, Name = R2, From = C, To = D" << std::endl;

    rm.addNewRoute(10, "R1", "A", "B");
    rm.addNewRoute(5, "R2", "C", "D");

    std::cout << "Displaying all routes:" << std::endl;
    rm.showAllRoutes();
    //==================================================================================

    std::cout << std::endl;
    // Testing replacing a route with distance 5:
    std::cout << "Replacing the route with distance 5 with new data:" << std::endl;
    std::cout << "Before replacement:" << std::endl;
    rm.showAllRoutes();

    rm.replaceRoute(5, "NewRoute", "AA", "BB");

    std::cout << "After replacement:" << std::endl;
    rm.showAllRoutes();
    //==================================================================================

    std::cout << std::endl;
    // Testing getting the first route:
    std::cout << "Trying to get the first route:" << std::endl;
    rm.showFirstRoute();
    //==================================================================================

    std::cout << std::endl;
    // Testing removing a route:
    std::cout << "Trying to remove a route:" << std::endl;
    std::cout << "Before removal:" << std::endl;
    rm.showAllRoutes();

    rm.removeRoute(5);

    std::cout << "After removal:" << std::endl;
    rm.showAllRoutes();
    //==================================================================================

    std::cout << std::endl;
    // Testing removing a route that does not exist:
    std::cout << "Trying to remove a route that does not exist (Distance = 111):" << std::endl;
    rm.removeRoute(111);
    //==================================================================================

    std::cout << std::endl;
    // Testing replacing a route that does not exist:
    std::cout << "Trying to replace a route that does not exist (Distance = 111):" << std::endl;
    rm.replaceRoute(111, "a", "aa", "aaa");
    //==================================================================================

    std::cout << std::endl;
    // Testing adding routes with distance 0 and -1:
    std::cout << "Trying to add a route with distance 0:" << std::endl;
    rm.addNewRoute(0, "a", "aa", "aaa");

    std::cout << "Trying to add a route with distance -1:" << std::endl;
    rm.addNewRoute(-1, "a", "aa", "aaa");
    //==================================================================================

    std::cout << std::endl;
    // Testing adding a route with a distance that already exists:
    std::cout << "Testing adding a route with a distance that already exists:" << std::endl;

    std::cout << "Current routes in the map:" << std::endl;
    rm.showAllRoutes();

    std::cout << "Attempting to add a route with the following details:" << std::endl;
    std::cout << "Distance = 10, Name = a, From = aa, To = aaa" << std::endl;

    rm.addNewRoute(10, "a", "aa", "aaa");
    //==================================================================================


    return 0;
}