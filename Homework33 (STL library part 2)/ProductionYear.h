#pragma once
class ProductionYear
{
private:

	size_t year;

    int getCurrentYear() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* parts = std::localtime(&now_c);
        return 1900 + parts->tm_year;
    }

public:

	ProductionYear(size_t year);

    int getYear() const { return this->year; }
};

