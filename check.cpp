#include <iostream>
#include <string>
#include <vector>

class MenuItem {
public:
    std::string name;
    double price;

    MenuItem(std::string n, double p) : name(n), price(p) {}
};

class Cafe {
private:
    std::vector<MenuItem> menu;
public:
    void addItem(std::string name, double price) {
        menu.push_back(MenuItem(name, price));
    }

    void displayMenu() {
        std::cout << "Menu:\n";
        for (const auto& item : menu) {
            std::cout << item.name << " - $" << item.price << "\n";
        }
    }

    double calculateTotal(const std::vector<int>& order) {
        double total = 0.0;
        for (int index : order) {
            if (index >= 0 && index < menu.size()) {
                total += menu[index].price;
            }
        }
        return total;
    }
};

int main() {
    Cafe cafe;
    cafe.addItem("Coffee", 2.50);
    cafe.addItem("Tea", 1.75);
    cafe.addItem("Sandwich", 5.00);

    cafe.displayMenu();

    std::vector<int> order = {0, 2}; // Example order: Coffee and Sandwich
    double total = cafe.calculateTotal(order);

    std::cout << "Total: $" << total << "\n";

    return 0;
}