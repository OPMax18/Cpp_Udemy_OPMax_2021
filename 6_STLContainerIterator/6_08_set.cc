
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>

void print_set(std::set<std::string>& set)
{
    std::cout << "Set: "
              << "\n"
              << "Value: \n";
    for (const auto& value : set)
    {
        std::cout << value << "\t";
    }
    std::cout << "\n";
}

int main()
{

    std::set<std::string> myMathCourse;
    std::cout << "myMathCourse: \n";
    myMathCourse.insert("Jan");
    myMathCourse.insert("Uwe");
    myMathCourse.insert("Dennis");
    myMathCourse.insert("Peter");
    print_set(myMathCourse);
    std::cout << "\n";

    std::set<std::string> myCodingCourse;
    std::cout << "myCodingCourse: \n";
    myCodingCourse.insert("Jan");
    myCodingCourse.insert("Nina");
    myCodingCourse.insert("Mats");
    myCodingCourse.insert("Sophie");
    myCodingCourse.insert("Albert");
    print_set(myCodingCourse);
    std::cout << "\n";

    // Set Union
    std::cout << "Union: \n";
    std::set<std::string> studentsUnion;
    std::set_union(myMathCourse.begin(),
                   myMathCourse.end(),
                   myCodingCourse.begin(),
                   myCodingCourse.end(),
                   std::inserter(studentsUnion, studentsUnion.end()));
    print_set(studentsUnion);
    std::cout << "\n";

    // Set Intersection
    std::cout << "Intersection: \n";
    std::set<std::string> studentsIntersection;
    std::set_intersection(myMathCourse.begin(),
                          myMathCourse.end(),
                          myCodingCourse.begin(),
                          myCodingCourse.end(),
                          std::inserter(studentsIntersection, studentsIntersection.end()));
    print_set(studentsIntersection);
    std::cout << "\n";

    // Set Difference
    std::cout << "Difference: \n";
    std::set<std::string> studentsDifference;
    std::set_difference(myMathCourse.begin(),
                        myMathCourse.end(),
                        myCodingCourse.begin(),
                        myCodingCourse.end(),
                        std::inserter(studentsDifference, studentsDifference.end()));
    print_set(studentsDifference);
    std::cout << "\n";

    // Set SymmetricDifference
    std::cout << "SymmetricDifference: \n";
    std::set<std::string> studentsSymmetricDifference;
    std::set_symmetric_difference(myMathCourse.begin(),
                                  myMathCourse.end(),
                                  myCodingCourse.begin(),
                                  myCodingCourse.end(),
                                  std::inserter(studentsSymmetricDifference, studentsSymmetricDifference.end()));
    print_set(studentsSymmetricDifference);
    std::cout << "\n";

    return 0;
}
