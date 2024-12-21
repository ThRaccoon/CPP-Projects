#include <iostream>
#include <string>

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


void isInt(int& input);

int main()
{
    RouteManager rm;
    
    int choice;
    
    int distance;
    std::string name;
    std::string from;
    std::string to;

    while (true) 
    {
        system("cls");
        std::cout << "Route Management System" << std::endl;
        std::cout << "1. Add New Route" << std::endl;
        std::cout << "2. Replace Route" << std::endl;
        std::cout << "3. Remove Route" << std::endl;
        std::cout << "4. Show First Route" << std::endl;
        std::cout << "5. Show All Routes" << std::endl;
        std::cout << "6. Preset Test" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Choose an option: " << std::endl;

        std::cin >> choice;
        isInt(choice);

        if (choice == 7) 
        {
            system("cls");
            std::cout << "Thanks for using my program!" << std::endl;
            
            break;
        }

        switch (choice) 
        {
        case 1: 
        {
            std::cout << "Enter distance: (Only integers!)" << std::endl;
            std::cin >> distance;
            isInt(choice);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            std::cout << "Enter route name: " << std::endl;
            std::getline(std::cin, name);
            
            std::cout << "Enter starting point: " << std::endl;
            std::getline(std::cin, from);
            
            std::cout << "Enter destination: " << std::endl;
            std::getline(std::cin, to);
            
            rm.addNewRoute(distance, name, from, to);
            
            break;
        }
        case 2: 
        {
            std::cout << "Enter distance of the route to replace: (Only integers!)" << std::endl;
            std::cin >> distance;
            isInt(choice);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            std::cout << "Enter new route name: " << std::endl;
            std::getline(std::cin, name);
            
            std::cout << "Enter new starting point: " << std::endl;
            std::getline(std::cin, from);
            
            std::cout << "Enter new destination: " << std::endl;
            std::getline(std::cin, to);
            
            rm.replaceRoute(distance, name, from, to);
            
            break;
        }
        case 3: 
        {
            std::cout << "Enter distance of the route to remove: (Only integers!)" << std::endl;
            std::cin >> distance;
            isInt(choice);
            
            rm.removeRoute(distance);
            
            break;
        }
        case 4:
            rm.showFirstRoute();
            
            std::cout << std::endl;
            std::cout << "Press anything to continue: " << std::endl;
            std::cout << "> ";
            std::cin >> to;
            
            break;

        case 5:
            rm.showAllRoutes();
            
            std::cout << std::endl;
            std::cout << "Press anything to continue: " << std::endl;
            std::cout << "> ";
            std::cin >> to;
            
            break;

        case 6:
            system("cls");
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
            std::cout << "Adding two routes to check if the map sorts them by distance:" << std::endl;
            std::cout << "First route: Distance = 10, Name = R1, From = A, To = B" << std::endl;
            std::cout << "Second route: Distance = 5, Name = R2, From = C, To = D" << std::endl;

            rm.addNewRoute(10, "R1", "A", "B");
            rm.addNewRoute(5, "R2", "C", "D");

            std::cout << "Displaying all routes:" << std::endl;
            rm.showAllRoutes();
            //==================================================================================

            std::cout << std::endl;
            std::cout << "Replacing the route with distance 5 with new data:" << std::endl;
            std::cout << "Before replacement:" << std::endl;
            rm.showAllRoutes();

            rm.replaceRoute(5, "NewRoute", "AA", "BB");

            std::cout << "After replacement:" << std::endl;
            rm.showAllRoutes();
            //==================================================================================

            std::cout << std::endl;
            std::cout << "Trying to get the first route:" << std::endl;
            rm.showFirstRoute();
            //==================================================================================

            std::cout << std::endl;
            std::cout << "Trying to remove a route:" << std::endl;
            std::cout << "Before removal:" << std::endl;
            rm.showAllRoutes();

            rm.removeRoute(5);

            std::cout << "After removal:" << std::endl;
            rm.showAllRoutes();
            //==================================================================================

            std::cout << std::endl;
            std::cout << "Trying to remove a route that does not exist (Distance = 111):" << std::endl;
            rm.removeRoute(111);
            //==================================================================================

            std::cout << std::endl;
            // Testing replacing a route that does not exist:
            std::cout << "Trying to replace a route that does not exist (Distance = 111):" << std::endl;
            rm.replaceRoute(111, "a", "aa", "aaa");
            //==================================================================================

            std::cout << std::endl;
            std::cout << "Trying to add a route with distance 0:" << std::endl;
            rm.addNewRoute(0, "a", "aa", "aaa");

            std::cout << "Trying to add a route with distance -1:" << std::endl;
            rm.addNewRoute(-1, "a", "aa", "aaa");
            //==================================================================================

            std::cout << std::endl;
            std::cout << "Testing adding a route with a distance that already exists:" << std::endl;

            std::cout << "Current routes in the map:" << std::endl;
            rm.showAllRoutes();

            std::cout << "Attempting to add a route with the following details:" << std::endl;
            std::cout << "Distance = 10, Name = a, From = aa, To = aaa" << std::endl;

            rm.addNewRoute(10, "a", "aa", "aaa");
            //==================================================================================
            
            rm.removeRoute(10);

            std::cout << std::endl;
            std::cout << "Press anything to continue: " << std::endl;
            std::cout << "> ";
            std::cin >> to;

            break;

        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            
            std::cout << std::endl;
            std::cout << "Press anything to continue: " << std::endl;
            std::cout << "> ";
            std::cin >> to;
            
            break;
        }
    }

    return 0;
}

void isInt(int& input)
{
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();

        std::cin >> input;
    }
}