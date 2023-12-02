#include <iostream>
#include <bitset>

std::string text_to_binary(const std::string& text) {
    std::string binary_result;
    for (unsigned char c : text) {
        // Convert each character in the text to its binary representation
        binary_result += std::bitset<8>(c).to_string() + ' ';
    }
    return binary_result;
}

std::string vigenere_encrypt(const std::string& plaintext, const std::string& key) {
    std::string encrypted_text;
    size_t key_index = 0;

    for (unsigned char c : plaintext) {
        // XOR operation on the binary representation of characters
        unsigned char encrypted_char = c ^ key[key_index];
        encrypted_text += encrypted_char;

        // Move to the next key character
        key_index = (key_index + 1) % key.length();
        
        // Output the encryption process for each character
        std::cout << "Encrypting '" << c << "' with '" << key[key_index] << "': "
                  << std::bitset<8>(c) << " XOR " << std::bitset<8>(key[key_index]) 
                  << " = " << std::bitset<8>(encrypted_char) << " ('" << encrypted_char << "')\n";
    }

    return encrypted_text;
}

std::string vigenere_decrypt(const std::string& ciphertext, const std::string& key) {
    std::string decrypted_text;
    size_t key_index = 0;

    for (unsigned char c : ciphertext) {
        // XOR operation on the binary representation of characters
        unsigned char decrypted_char = c ^ key[key_index];
        decrypted_text += decrypted_char;

        // Move to the next key character
        key_index = (key_index + 1) % key.length();
        
        // Output the decryption process for each character
        std::cout << "Decrypting '" << c << "' with '" << key[key_index] << "': "
                  << std::bitset<8>(c) << " XOR " << std::bitset<8>(key[key_index]) 
                  << " = " << std::bitset<8>(decrypted_char) << " ('" << decrypted_char << "')\n";
    }

    return decrypted_text;
}

int main() {
    // Input plaintext and key from the user
    std::string plaintext, key;
    std::cout << "Enter the plaintext: ";
    std::getline(std::cin, plaintext);
    std::cout << "Enter the key: ";
    std::getline(std::cin, key);

    // Check if the key is empty
    if (key.empty()) {
        std::cout << "Key cannot be empty." << std::endl;
        return 1;
    }

    // Encryption
    std::cout << "\nEncryption Process:\n";
    std::string encrypted_text = vigenere_encrypt(plaintext, key);
    std::cout << "\nEncrypted Text: " << encrypted_text << std::endl;
    std::cout << "Binary: " << text_to_binary(encrypted_text) << std::endl;

    // Decryption
    std::cout << "\nDecryption Process:\n";
    std::string decrypted_text = vigenere_decrypt(encrypted_text, key);
    std::cout << "\nDecrypted Text: " << decrypted_text << std::endl;
    std::cout << "Binary: " << text_to_binary(decrypted_text) << std::endl;

    return 0;
}