/* Encoding program made by natsud
 * How it works: convert every character in the string to its
 * ASCII decimal number(8 bits), put these bits all together and save
 * them in a string 
 * To decode the string go through it and stop at every eight bit
 * convert these eight bits back to its decimal number and then convert the 
 * decimal number to its ASCII character */
#include <iostream>
#include <vector>
#include <string>

const std::string encode(const std::string&);
const std::string decode(const std::string&);

const std::string decimalToBit(const short&);
const short BitToDecimal(const std::string&);

int main()
{
	std::cout << "----------------Encoding-------------------" << std::endl;
	std::cout << "-Instead of space use the underline '_'   -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::string decode_s;
	std::string encode_s;
	std::string sentence;
	std::cout << "Enter a sentence: ";
	std::cin >> sentence;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cin.ignore();
	std::cin.sync();
	std::cin.clear();

	encode_s = encode(sentence);

	std::cout << "Encoded" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << encode_s << std::endl;

	

	decode_s = decode(encode_s);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Decoded" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << decode_s << std::endl;

	getchar();
}

const std::string decode(const std::string& encode_p)
{
	short number;
	std::string encodeTemp(encode_p);
	std::string sentence;
	std::string bits = "";
	char character;


	short actualPos = 0;

	for (int i = (encodeTemp.length() / 8) - 1; i >= 0; --i)
	{
		bits.clear();
		bits = "";
		// Get the first 8 bytes from the string and save in bits
		for (int j = 0; j < 8; ++j)
		{
			character = (encodeTemp.at(actualPos));
			bits += character;
			actualPos++;
		}
		std::cout << "Decode Info bits found: " << bits << std::endl;
		//// Get the number behind the bit
		number = BitToDecimal(bits);
		character = number;
		sentence += character;
	}

	return sentence;
}

const short BitToDecimal(const std::string& bits)
{
	short decimal = 0;

	if (bits.at(7) == '1')
		decimal += 1;

	if (bits.at(6) == '1')
		decimal += 2;

	if (bits.at(5) == '1')
		decimal += 4;

	if (bits.at(4) == '1')
		decimal += 8;

	if (bits.at(3) == '1')
		decimal += 16;

	if (bits.at(2) == '1')
		decimal += 32;

	if (bits.at(1) == '1')
		decimal += 64;

	if (bits.at(0) == '1')
		decimal += 128;

	return decimal;
}

// Get every character in the sentence convert them in bits
// and save these bits in a string
const std::string encode(const std::string& sentence)
{
	short number;
	std::string bits;
	
	for (const auto s : sentence)
	{
		number = static_cast<short>(s);
		bits += decimalToBit(number);
	}
	return bits;
}

const std::string decimalToBit(const short& number)
{
	std::string bits = "";
	for (int i = 7; i >= 0; --i)
	{
		if ((number & 1 << i) > 0)
		{
			bits += "1";
		}
		else if ((number & 1 << i) == 0)
		{
			bits += "0";
		}
	}
	return bits;
}
