#include "8_01_image.h"

Image::Image() : m_width(0), m_height(0), m_matrix(greyscale_matrix_type(m_width, std::vector<uchar>(m_height, 0)))
{
    std::cout << "Image object constructed with width:\t" << m_width << " and heigth: \t" << m_height << "\n";
    std::cout << "m_matrix rows:\t" << m_matrix.size() << " and columns: \t" << m_matrix[0].size() << "\n";
}

Image::Image(const unsigned int& width, const unsigned int& height)
    : m_width(width), m_height(height), m_matrix(greyscale_matrix_type(m_width, std::vector<uchar>(m_height, 0)))
{
    std::cout << "Image object constructed with width:\t" << m_width << " and heigth: \t" << m_height << "\n";
    std::cout << "m_matrix rows:\t" << m_matrix.size() << " and columns: \t" << m_matrix[0].size() << "\n";
}

Image::~Image()
{
    std::cout << "Image object destroyed!\n";
}

unsigned int Image::get_width() const
{
    return m_width;
}
unsigned int Image::get_height() const
{
    return m_height;
}

void Image::set_width(unsigned int new_width)
{
    m_width = new_width;
}
void Image::set_height(unsigned int new_height)
{
    m_height = new_height;
}

void Image::save_image(const char* file_name) const
{
    FILE* f = nullptr;

    auto num_bytes = 3 * m_width * m_height;
    auto* img = new uchar[num_bytes]{};

    auto filesize = 54 + 3 * m_width * m_height;

    for (std::uint32_t x = 0; x < m_width; ++x)
    {
        for (std::uint32_t y = 0; y < m_height; y++)
        {
            img[(x + y * m_width) * 3 + 2] = m_matrix[x][y] % 256;
            img[(x + y * m_width) * 3 + 1] = m_matrix[x][y] % 256;
            img[(x + y * m_width) * 3 + 0] = m_matrix[x][y] % 256;
        }
    }

    uchar bmpfileheader[14]{'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    uchar bmpinfoheader[40]{40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    uchar bmppad[3]{0, 0, 0};

    bmpfileheader[2] = static_cast<uchar>(filesize);
    bmpfileheader[3] = static_cast<uchar>(filesize >> 8);
    bmpfileheader[4] = static_cast<uchar>(filesize >> 16);
    bmpfileheader[5] = static_cast<uchar>(filesize >> 24);

    bmpinfoheader[4] = static_cast<uchar>(m_width);
    bmpinfoheader[5] = static_cast<uchar>(m_width >> 8);
    bmpinfoheader[6] = static_cast<uchar>(m_width >> 16);
    bmpinfoheader[7] = static_cast<uchar>(m_width >> 24);
    bmpinfoheader[8] = static_cast<uchar>(m_height);
    bmpinfoheader[9] = static_cast<uchar>(m_height >> 8);
    bmpinfoheader[10] = static_cast<uchar>(m_height >> 16);
    bmpinfoheader[11] = static_cast<uchar>(m_height >> 24);

    f = fopen(file_name, "wb");
    if (f == nullptr)
    {
        delete[] img;
        img = nullptr;

        return;
    }

    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    for (std::uint32_t i = 0; i < m_height; i++)
    {
        fwrite(img + (m_width * (m_height - i - 1) * 3), 3, m_width, f);
        fwrite(bmppad, 1, (4 - (m_width * 3) % 4) % 4, f);
    }

    fclose(f);
    f = nullptr;

    delete[] img;
    img = nullptr;
}
