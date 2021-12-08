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
    kAdmin = 4,
    kUnkown = 5
};

struct UserData
{
    char* name; // C style
    unsigned int id;
    PermissionLevel permissionLevel;
};

void greet_permission_level(PermissionLevel level)
{
    switch (level)
    {
    case PermissionLevel::kStudent:
        cout << "Hello Student \n";
        break;
    case PermissionLevel::kTutor:
        cout << "Hello Tutor \n";
        break;
    case PermissionLevel::kInstructor:
        cout << "Hello Instructor \n";
        break;
    case PermissionLevel::kAdmin:
        cout << "Hello Admin \n";
        break;
    default:
        cout << "Unknown! ERROR!! \n";
        break;
    }
}

int main()
{

    PermissionLevel permissionLevelPeter = PermissionLevel::kInstructor;
    PermissionLevel permissionLevelUwe = PermissionLevel::kStudent;

    UserData userPeter{"Peter", 108106, permissionLevelPeter};

    UserData userUwe;
    userUwe.name = "Uwe";
    userUwe.id = 108107;
    userUwe.permissionLevel = permissionLevelUwe;

    greet_permission_level(userPeter.permissionLevel);
    greet_permission_level(userUwe.permissionLevel);


    return 0;
}
