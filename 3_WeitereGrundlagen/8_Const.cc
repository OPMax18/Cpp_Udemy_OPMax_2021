#include <iostream>

//#define NUM_VEHICLES 3
constexpr int kDefaultVehicleId = -1;
constexpr unsigned kNumVehicles = 3;

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
    int id;
    float velocity;
    Lane lane;
};


// const&: Read-only

// Only for completness
// *const <=> &
// const* const: Same as const&
void print_vehicle_data(const Vehicle& vehicle)
{
    cout << "Vehicle ID: \t\t\t" << vehicle.id << "\n";
    cout << "Vehicle Velocity [kph]: \t" << vehicle.velocity << "\n";

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


int main()
{

    Vehicle vehicle1 = {1U, 100.0f, Lane::kCenterLane};

    // available for C++ 20 and also for a lot of compiler!!
    Vehicle vehicle2 = {.id = 2U, .velocity = 132.3f, .lane = Lane::kLeftLane};
    Vehicle vehicle3 = {.id = kDefaultVehicleId, .velocity = 63.5f, .lane = Lane::kRightLane};

    Vehicle vehicleInScene[kNumVehicles] = {vehicle1, vehicle2, vehicle3};

    for (unsigned int i = 0U; i < kNumVehicles; ++i)
    {
        print_vehicle_data(vehicleInScene[i]);
    }


    return 0;
}
