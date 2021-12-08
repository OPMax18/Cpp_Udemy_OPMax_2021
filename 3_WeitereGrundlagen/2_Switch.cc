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

void greet_permission_level_if(PermissionLevel level)
{
    if (level == PermissionLevel::kStudent)
    {
        cout << "Hello Student \n";
    }
    else if (level == PermissionLevel::kTutor)
    {
        cout << "Hello Tutor \n";
    }
    else if (level == PermissionLevel::kInstructor)
    {
        cout << "Hello Instructor \n";
    }
    else if (level == PermissionLevel::kAdmin)
    {
        cout << "Hello Admin \n";
    }
    else
    {
        cout << "Unknown! ERROR!! \n";
    }
}

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
    greet_permission_level_if(permissionLevelPeter);
    greet_permission_level(permissionLevelPeter);

    PermissionLevel permissionLevelUwe = PermissionLevel::kStudent;
    greet_permission_level_if(permissionLevelUwe);
    greet_permission_level(permissionLevelUwe);

    return 0;
}
