#pragma once

using json = nlohmann::json;

// interface for serializabe object
class Serializable
{
public:

	virtual json serialize() const = 0;
};

