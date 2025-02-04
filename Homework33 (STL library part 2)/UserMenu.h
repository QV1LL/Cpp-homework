#pragma once

class UserMenu {
private:

    std::unique_ptr<CarDealership> dealership;

    static std::shared_ptr<UserMenu> instance;

    explicit UserMenu(std::unique_ptr<CarDealership> dealership);

public:

    static std::shared_ptr<UserMenu> getInstance(std::unique_ptr<CarDealership> dealership);

    void sortCarsByCondition();
    void showMenu();
    void addCarToDealership();
    void deleteCarFromDealership();
};