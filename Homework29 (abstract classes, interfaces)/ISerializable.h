#pragma once

#include "json.hpp"

using json = nlohmann::json;

class ISerializable
{
public:

	virtual json serialize() const = 0;

	virtual void deserialize(const json& serializedObject) = 0;

	virtual ~ISerializable() = default;

};

