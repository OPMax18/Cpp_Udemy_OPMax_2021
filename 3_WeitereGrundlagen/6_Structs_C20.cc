#include <iostream>

using std::cin;
using std::cout;
using std::endl;

enum class Lane
{
    kRightLane,
    kCenterLane,
    kLeftLane
};

struct Vehicle
{
    unsigned int id;
    float velocity;
    Lane lane;
};

void print_vehicle_data(Vehicle& vehicle)
{
    cout << "Vehicle ID: \t\t\t" << vehicle.id << "\n";
    cout << "Vehicle Velocity [kph]: \t" << vehicle.velocity << "\n";
    // // direct cout is not possible due to type cast necessary
    // cout << "Vehicle Lane Association: \t" << vehicle.lane << "\n";

    switch (vehicle.lane)
    {
    case Lane::kLeftLane:
        cout << "Vehicle Lane Association: \t"
             << "Left Lane"
             << "\n";
        break;
    case Lane::kCenterLane:
        cout << "Vehicle Lane Association: \t"
             << "Center Lane"
             << "\n";
        break;
    case Lane::kRightLane:
        cout << "Vehicle Lane Association: \t"
             << "Rigth Lane"
             << "\n";
        break;
    default:
        cout << "Vehicle Lane Association: \t"
             << "Lane Error"
             << "\n";
        break;
    }
}


void print_vehicle_data_pointer(Vehicle* vehicle)
{
    cout << "Vehicle ID: \t\t\t" << (*vehicle).id << "\n";
    cout << "Vehicle Velocity [kph]: \t" << vehicle->velocity << "\n";
    // // direct cout is not possible due to type cast necessary
    // cout << "Vehicle Lane Association: \t" << vehicle.lane << "\n";

    switch (vehicle->lane)
    {
    case Lane::kLeftLane:
        cout << "Vehicle Lane Association: \t"
             << "Left Lane"
             << "\n";
        break;
    case Lane::kCenterLane:
        cout << "Vehicle Lane Association: \t"
             << "Center Lane"
             << "\n";
        break;
    case Lane::kRightLane:
        cout << "Vehicle Lane Association: \t"
             << "Rigth Lane"
             << "\n";
        break;
    default:
        cout << "Vehicle Lane Association: \t"
             << "Lane Error"
             << "\n";
        break;
    }
}

int main()
{

    Vehicle vehicle1 = {1U, 100.0f, Lane::kCenterLane};

    // available for C++ 20 and also for a lot of compiler!!
    Vehicle vehicle2 = {.id = 2U, .velocity = 80.3f, .lane = Lane::kLeftLane};

    print_vehicle_data(vehicle1);
    print_vehicle_data_pointer(&vehicle1);

    print_vehicle_data(vehicle2);
    print_vehicle_data_pointer(&vehicle2);
    return 0;
}
