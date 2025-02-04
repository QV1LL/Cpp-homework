#pragma once
class ProductionYear
{
private:

	size_t year;

    int getCurrentYear() {
        using namespace std::chrono;
        auto now = system_clock::now();
        auto nowTime = year_month_day{ floor<days>(now) };
        return static_cast<int>(nowTime.year());
    }

public:

	ProductionYear(size_t year);

    int getYear() const { return this->year; }
};

