#pragma once

class UserMenu {
private:

    std::unique_ptr<CarDealership> dealership;

    static std::shared_ptr<UserMenu> instance;

    UserMenu(std::unique_ptr<CarDealership> dealership);

public:

    static std::shared_ptr<UserMenu> getInstance();

    void showMenu() {
        int choice;
        do {
            std::cout << "\nCar Dealership Menu:\n";
            std::cout << "1. Add Car\n2. Delete Car\n3. Display Cars\n4. Sort Cars by Year\n5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                addCarToDealership();
                break;
            case 2:
                deleteCarFromDealership();
                break;
            case 3:
                dealership.displayCars();
                break;
            case 4:
                dealership.sortCarsByYear();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 5);
    }

    void addCarToDealership() {
        std::string brand, model, currency;
        size_t year;
        float engineVolume;
        int engineType;
        double priceAmount;

        std::cout << "Enter brand: ";
        std::cin >> brand;
        std::cout << "Enter model: ";
        std::cin >> model;
        std::cout << "Enter year: ";
        std::cin >> year;
        std::cout << "Enter engine volume: ";
        std::cin >> engineVolume;
        std::cout << "Enter engine type (0: Petrol, 1: Diesel, 2: Electric, 3: Hybrid): ";
        std::cin >> engineType;
        std::cout << "Enter price amount: ";
        std::cin >> priceAmount;
        std::cout << "Enter currency: ";
        std::cin >> currency;

        dealership.addCar(Car{ brand, model, year, engineVolume, static_cast<EngineType>(engineType), { priceAmount, currency } });
    }

    void deleteCarFromDealership() {
        int carId;
        std::cout << "Enter car ID to delete: ";
        std::cin >> carId;
        dealership.deleteCarById(carId);
    }

