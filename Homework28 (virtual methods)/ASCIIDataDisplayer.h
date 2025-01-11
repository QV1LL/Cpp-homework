#pragma once

class ASCIIDataDisplayer : public DataDisplayer
{
private:

	static ASCIIDataDisplayer* instance;

	ASCIIDataDisplayer() = default;

public:

	static ASCIIDataDisplayer* getInstance();

	virtual void display(const char* path) const override;

};

