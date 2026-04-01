#include <iostream>
#include <vector>
#include <string>

class Marker {
public:
    std::string name;
    Marker(std::string n) : name(n) {}
};

class MarkerManager {
private:
    std::vector<Marker> markers;
public:
    void displayMarkers() {
        if (markers.empty()) {
            std::cout << "No markers available." << std::endl;
            return;
        }
        std::cout << "Markers List:" << std::endl;
        for (size_t i = 0; i < markers.size(); i++) {
            std::cout << i + 1 << ". " << markers[i].name << std::endl;
        }
    }

    void addMarker(std::string name) {
        markers.push_back(Marker(name));
        std::cout << "Marker added: " << name << std::endl;
    }

    void removeMarker(int index) {
        if (index < 1 || index > markers.size()) {
            std::cout << "Invalid index. Please try again." << std::endl;
            return;
        }
        std::string removedName = markers[index - 1].name;
        markers.erase(markers.begin() + (index - 1));
        std::cout << "Marker removed: " << removedName << std::endl;
    }
};

int main() {
    MarkerManager manager;
    int choice;
    std::string name;

    do {
        std::cout << "\nMarker Management Menu" << std::endl;
        std::cout << "1. Display Markers" << std::endl;
        std::cout << "2. Add Marker" << std::endl;
        std::cout << "3. Remove Marker" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manager.displayMarkers();
                break;
            case 2:
                std::cout << "Enter marker name: ";
                std::cin >> name;
                manager.addMarker(name);
                break;
            case 3:
                int index;
                std::cout << "Enter marker index to remove: ";
                std::cin >> index;
                manager.removeMarker(index);
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
