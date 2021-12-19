#include "exercise.h"


// In eurem Programm bitte:
// your_main zu main ändern
int main()
{
    // Aufgabe 1
    friends_type myFriendsMap;
    myFriendsMap["Jan"] = pair_age_weight(35U, 80U);
    myFriendsMap["Sophie"] = pair_age_weight(32U, 55U);
    myFriendsMap["Anne"] = pair_age_weight(38U, 58U);

    // Aufgabe 2

    std::cout << "My oldest friend: \t" << get_oldest_friend(myFriendsMap) << "\n";
    std::cout << "My haviest friend: \t" << get_heaviest_friend(myFriendsMap) << "\n";

    cin.get();
    getchar();
    return 0;
}
