#include "Image.h"

Image::Image() : m_width(0), m_height(0), m_matrix(GrayscaleMatrix(m_width, std::vector<uchar>(m_height, 0)))
{
    std::cout << "Created empty image object!" << std::endl;
}

Image::Image(const unsigned int width, const unsigned int height)
    : m_width(width), m_height(height), m_matrix(GrayscaleMatrix(m_width, std::vector<uchar>(m_height, 0)))
{
    std::cout << "Created image object with shape=(" << m_width << "," << m_height << ")!" << std::endl;
    std::cout << "Matrix size: (" << m_matrix.size() << "," << m_matrix[0].size() << ")" << std::endl;
}

Image::~Image()
{
    std::cout << "Image object destroyed!" << std::endl;
}

unsigned int Image::get_width() const
{
    return m_width;
}

unsigned int Image::get_height() const
{
    return m_height;
}

// Aufgabe 1
void Image::clear_image()
{
    m_matrix.clear();
    m_width = 0U;
    m_height = 0U;
}

// Aufgabe 2
void Image::set_pixel(const unsigned int x, const unsigned int y, const uchar value)
{
    m_matrix[x][y] = value;
}

// Aufgabe 3
void Image::resize_image(const unsigned int new_width, const unsigned int new_height)
{

    // Image new_image(new_width, new_height);
    // for (unsigned int i = 0; i < new_width && i < m_width; ++i)
    // {
    //     for (unsigned int j = 0; j < new_height && j < m_height; ++j)
    //     {
    //         //new_image.m_matrix[i][j] = m_matrix[i][j];
    //         new_image.m_matrix[i][j] = 100;
    //     }
    // }
    // m_matrix.clear();
    // std::vector<uchar> new_row{};
    // for (auto row : new_image.m_matrix)
    // {
    //     new_row.clear();
    //     for (auto pix_value : row)
    //     {
    //         new_row.push_back(pix_value);
    //     }
    //     m_matrix.push_back(new_row);
    // }

    // m_width = new_width;
    // m_height = new_height;

    // Nutzung der resize function ausreichend
    // New width
    if (new_width != m_width)
    {
        m_matrix.resize(new_width);
        m_width = new_width;
    }

    // New height
    if (new_height != m_height)
    {
        for (auto& col : m_matrix)
        {
            col.resize(new_height);
        }
        m_height = new_height;
    }
}

// Aufgabe 4
void Image::fill_image(const uchar value)
{
    for (auto& col : m_matrix)
    {
        // for (auto& pix_value : row)
        // {
        //     pix_value = value;
        // }
        std::fill(col.begin(), col.end(), value);
    }
}

// Aufgabe 5
void Image::draw_line(const unsigned int x1,
                      const unsigned int y1,
                      const unsigned int x2,
                      const unsigned int y2,
                      const uchar value)
{
    // Abfragen einführen, ob Werte in richtiger Reihenfolge und innerhalb des Bildes
    for (unsigned int i = x1; i <= x2; ++i)
    {
        for (unsigned int j = y1; j <= y2; ++j)
        {
            set_pixel(i, j, value);
            // m_matrix[i][j] = value;
        }
    }
}

void Image::save_image(const char* file_name) const
{
    FILE* f;

    unsigned int num_bytes = 3 * m_width * m_height;
    uchar* img = (uchar*)(malloc(num_bytes));
    memset(img, 0, num_bytes);

    int filesize = 54 + 3 * m_width * m_height;

    for (unsigned int x = 0; x < m_width; ++x)
    {
        for (unsigned int y = 0; y < m_height; y++)
        {
            img[(x + y * m_width) * 3 + 2] = m_matrix[x][y] % 256;
            img[(x + y * m_width) * 3 + 1] = m_matrix[x][y] % 256;
            img[(x + y * m_width) * 3 + 0] = m_matrix[x][y] % 256;
        }
    }

    uchar bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    uchar bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    uchar bmppad[3] = {0, 0, 0};

    bmpfileheader[2] = (uchar)(filesize);
    bmpfileheader[3] = (uchar)(filesize >> 8);
    bmpfileheader[4] = (uchar)(filesize >> 16);
    bmpfileheader[5] = (uchar)(filesize >> 24);

    bmpinfoheader[4] = (uchar)(m_width);
    bmpinfoheader[5] = (uchar)(m_width >> 8);
    bmpinfoheader[6] = (uchar)(m_width >> 16);
    bmpinfoheader[7] = (uchar)(m_width >> 24);
    bmpinfoheader[8] = (uchar)(m_height);
    bmpinfoheader[9] = (uchar)(m_height >> 8);
    bmpinfoheader[10] = (uchar)(m_height >> 16);
    bmpinfoheader[11] = (uchar)(m_height >> 24);

    f = fopen(file_name, "wb");
    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    for (unsigned int i = 0; i < m_height; i++)
    {
        fwrite(img + (m_width * (m_height - i - 1) * 3), 3, m_width, f);
        fwrite(bmppad, 1, (4 - (m_width * 3) % 4) % 4, f);
    }

    fclose(f);
}
