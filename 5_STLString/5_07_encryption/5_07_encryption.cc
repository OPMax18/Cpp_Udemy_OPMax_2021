#include "5_07_exercise.h"


int main()
{

    std::string content;
    std::ifstream iffile;
    iffile.open("text.txt", std::ios::in);
    if (iffile.is_open())
    {
        iffile >> content;
    }
    iffile.close();
    std::cout << "text content: \n" << content << "\n\n";

    ByteArray plainText(content.begin(), content.end());
    ByteArray key(8, 0xff);
    ByteArray cipher_text = hex_vector_xor(plainText, key);

    for (std::size_t i = 0; i < cipher_text.size(); ++i)
    {
        std::cout << "cipher_text[" << i << "]: \t" << cipher_text[i] << "\n";
    }
    std::cout << "\n\n";

    ByteArray message = hex_vector_xor(cipher_text, key);
    for (std::size_t i = 0; i < message.size(); ++i)
    {
        std::cout << "message[" << i << "]: \t" << message[i] << "\n";
    }
    std::cout << "\n\n";

    return 0;
}
