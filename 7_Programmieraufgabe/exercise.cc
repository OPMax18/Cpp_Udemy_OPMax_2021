#include "exercise.h"

// Aufgabe 2
string get_oldest_friend(const friends_type& friends)
{
    string name = "";
    int age = 0U;
    for (const auto& myFriend : friends)
    {
        if (myFriend.second.first > age)
        {
            name = myFriend.first;
            age = myFriend.second.first;
        }
    }
    return name;
}

string get_heaviest_friend(const friends_type& friends)
{
    string name = "";
    int weight = 0U;
    for (const auto& myFriend : friends)
    {
        if (myFriend.second.second > weight)
        {
            name = myFriend.first;
            weight = myFriend.second.second;
        }
    }
    return name;
}
