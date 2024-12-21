#pragma once

#include "String.h"

class ByteString : public String
{
private:

    bool isNegative;

public:

    explicit ByteString(const char* byteStream, bool isNegative = false);
    ByteString(const ByteString& byteString);

    void setPositiveSign();
    void setNegativeSign();

    ByteString& operator=(const ByteString& other);
    ByteString& operator+=(const ByteString& other);
    ByteString operator+(const ByteString& other);

    ~ByteString();
};

