#pragma once

class BinaryDataDisplayer : public DataDisplayer
{
private:

	static BinaryDataDisplayer* instance;

	BinaryDataDisplayer() = default;

public:

	static BinaryDataDisplayer* getInstance();

	virtual void display(const char* path) const override;

};

