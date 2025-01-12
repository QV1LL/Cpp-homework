#pragma once

using json = nlohmann::json;

// interface for serializabe object
class ISerializable
{
public:

	virtual json serialize() const = 0;
};

