#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Enum values are constant
// Enum values are integers

enum PermissionLevel
{
    kStudent = 1,
    kTutor = 2,
    kInstructor = 3,
    kAdmin = 4
};

int main()
{

    PermissionLevel permissionLevelPeter = PermissionLevel::kInstructor;
    PermissionLevel permissionLevelUwe = PermissionLevel::kStudent;


    return 0;
}
