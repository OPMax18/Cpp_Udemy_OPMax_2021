#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <vector>

using uchar = unsigned char;
using greyscale_matrix_type = std::vector<std::vector<uchar>>;

class Image
{
public:
    // constructor
    Image();
    //Image() = delete;
    Image(const unsigned int& width, const unsigned int& height);

    // destructor
    ~Image();

    void save_image(const char* file_name) const;

    // Getter
    unsigned int get_width() const;
    unsigned int get_height() const;

    // Setter
    void set_width(unsigned int new_width);
    void set_height(unsigned int new_height);

private:
    // const unsigned int m_width;
    // const unsigned int m_height;
    unsigned int m_width;
    unsigned int m_height;
    greyscale_matrix_type m_matrix;
};
