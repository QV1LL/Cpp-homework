#pragma once

class DataDisplayer
{
private:

	static DataDisplayer* instance;

protected:

	DataDisplayer() = default;

public:

	static DataDisplayer* getInstance();
	virtual void display(const char* path) const;

	virtual ~DataDisplayer() = default;
};

