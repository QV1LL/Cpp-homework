#include "ByteString.h"

bool isByteStreamValid(const char* byteStream)
{
	for (int i = 0; i < strlen(byteStream); i++)
		if (byteStream[i] != '0' && byteStream[i] != '1')
			return false;

	return true;
}

ByteString::ByteString(const char* byteStream = "00000000", bool isNegative) : isNegative(isNegative)
{
	if (strlen(byteStream) != 8)
		throw std::invalid_argument("Byte stream size must be 8 (2 byte integer)");

	if (!isByteStreamValid(byteStream))
		throw std::invalid_argument("Byte stream cannot contain value different from '0' or '1'");

	this->text = new char[1024];
	this->size = strlen(byteStream) + 1;
	strcpy_s(this->text, this->size, byteStream);
}

ByteString::ByteString(const ByteString& other) : isNegative(isNegative)
{
	this->isNegative = other.isNegative;
	this->size = other.size;
	this->text = new char[1024];
	strcpy_s(this->text, this->size, other.text);
}

void ByteString::setPositiveSign()
{
	this->isNegative = false;
}

void ByteString::setNegativeSign()
{
	this->isNegative = true;
}


ByteString& ByteString::operator=(const ByteString& other)
{
	this->erase();

	*this = ByteString(other);

	return *this;
}

ByteString& ByteString::operator+=(const ByteString& other)
{
    bool overflow = false;    
    int length = 8;      
    int resultLength = length + 1;        
    char* result = new char[resultLength]; 

    for (int i = length - 1; i >= 0; --i) {
        char a = this->text[i];          
        char b = other.text[i];       

        int bitSum = (a - '0') + (b - '0') + overflow; 

        if (bitSum == 0) {
            result[i + 1] = '0';      
            overflow = false;               
        }
        else if (bitSum == 1) {
            result[i + 1] = '1';          
            overflow = false;              
        }
        else if (bitSum == 2) {
            result[i + 1] = '0';           
            overflow = true;                  
        }
        else if (bitSum == 3) {
            result[i + 1] = '1';          
            overflow = true;
        }
    }

    if (overflow) {
        result[0] = '1';                    
    }
    else {
        memcpy(result, result + 1, length);
        result[length] = '\0';              
    }

    delete[] this->text;                   
    this->text = result;                   

    return *this;
}

ByteString ByteString::operator+(const ByteString& other)
{
    bool overflow = false;
    int length = 8;
    int resultLength = length + 1;
    char* result = new char[resultLength];

    for (int i = length - 1; i >= 0; --i) {
        char a = this->text[i];
        char b = other.text[i];

        int bitSum = (a - '0') + (b - '0') + overflow;

        if (bitSum == 0) {
            result[i + 1] = '0';
            overflow = false;
        }
        else if (bitSum == 1) {
            result[i + 1] = '1';
            overflow = false;
        }
        else if (bitSum == 2) {
            result[i + 1] = '0';
            overflow = true;
        }
        else if (bitSum == 3) {
            result[i + 1] = '1';
            overflow = true;
        }
    }

    if (overflow) {
        result[0] = '1';
    }
    else {
        memcpy(result, result + 1, length);
        result[length] = '\0';
    }

    return ByteString(result);
}

ByteString::~ByteString()
{
	this->erase();
}
