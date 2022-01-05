#pragma once

#include <cstddef>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**
 * @brief DynamicArray Class.
 *
 * @param m_data Pointer to the data array
 * @param m_length Length of the Array
 */
template <typename T_Data>
class DynamicArray
{
public:
    // Constructors
    DynamicArray();
    DynamicArray(const T_Data& value, const std::size_t length);
    ~DynamicArray();

    // Data-manipulation methods
    void push_back(const T_Data& value);
    void pop_back();

    // Operator overloading
    T_Data& operator[](const std::size_t index);
    const T_Data& operator[](const std::size_t index) const;

    // helper methods
    std::size_t get_length() const;

private:
    std::size_t m_length;
    std::size_t m_capacity;
    T_Data* m_data;
};

/**
 * @brief Create a empty dynamic array object
 *
 */
template <typename T_Data>
DynamicArray<T_Data>::DynamicArray() : m_length(0U), m_capacity(1), m_data(new T_Data[m_capacity])
{
}


/**
 * @brief Create a dynamic array object
 *
 * @param value  The fill value for the array
 * @param length The length of the dynamic array
 */
template <typename T_Data>
DynamicArray<T_Data>::DynamicArray(const T_Data& value, const std::size_t length)
    //    : m_length(length), m_capacity(length), m_data(new T_Data[m_length])
    : m_length(length), m_capacity(length > 0 ? length : 1U), m_data(nullptr)
{
    m_data = new T_Data[m_capacity];

    for (std::size_t i = 0; i < m_length; i++)
    {
        m_data[i] = value;
    }
}

/**
 * @brief Destroys a dynamic arry object
 *
 */
template <typename T_Data>
DynamicArray<T_Data>::~DynamicArray()
{
    delete[] m_data;
    m_data = nullptr;
}

/**
 * @brief Pushs back the *value* at the end of the array
 *
 * @param value         The value to append to the array
 */
template <typename T_Data>
void DynamicArray<T_Data>::push_back(const T_Data& value)
{
    if (m_length == m_capacity)
    {
        m_capacity *= 2U;
        T_Data* temp = nullptr;
        temp = new T_Data[m_capacity];

        for (std::size_t i = 0; i < m_length; i++)
        {
            temp[i] = m_data[i];
        }
        delete[] m_data;
        m_data = temp;
    }

    m_data[m_length] = value;
    m_length++;
}

/**
 * @brief Pops back the *value* at the end of the arry
 *
 */
template <typename T_Data>
void DynamicArray<T_Data>::pop_back()
{
    if (m_length > 0)
    {
        m_length--;
        if (m_length < (m_capacity / 2))
        {
            m_capacity /= 2U;
        }
        T_Data* temp = nullptr;
        temp = new T_Data[m_capacity];
        for (std::size_t i = 0; i < m_length; i++)
        {
            temp[i] = m_data[i];
        }

        delete[] m_data;
        m_data = temp;
    }
}

/**
 * @brief Return a reference to the entry selected by index
 *
 * @tparam T_Data
 * @param index         index of the current entry
 * @return              reference to the current value
 */
template <typename T_Data>
T_Data& DynamicArray<T_Data>::operator[](const std::size_t index)
{
    if (index < get_length())
    {
        return m_data[index];
    }
    else
    {
        // This is not the correct way to do it
        T_Data* temp = nullptr;
        temp = new T_Data[0];
        return *temp;
    }
}

/**
 * @brief Return a const reference to the entry selected by index
 *
 * @tparam T_Data
 * @param index         index of the current entry
 * @return              const reference to the current value
 */
template <typename T_Data>
const T_Data& DynamicArray<T_Data>::operator[](const std::size_t index) const
{
    if (index < get_length())
    {
        return m_data[index];
    }
    else
    {
        return nullptr;
    }
}

/**
 * @brief Returns the length of the dynamic array
 *
 * @tparam T_Data
 * @return length       the lenght of the dynamic array
 */
template <typename T_Data>
std::size_t DynamicArray<T_Data>::get_length() const
{
    return m_length;
}
