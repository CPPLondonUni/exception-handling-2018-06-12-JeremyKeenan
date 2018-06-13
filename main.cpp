#include <iostream>
#include <string>
#include <unordered_map>


int main() {
    bool loop = true;
    const std::unordered_map<std::string, int> studentAges{
            {"john",    19},
            {"peter",   24},
            {"paul",    31},
            {"zoltan",  54},
            {"laurent", 90},
            {"justin",  12},
            {"oliver",  1337}
    };

    while (loop) {
    try {
        std::cout << "Enter a name: " << std::endl;
        std::string name;
        std::cin >> name;
        //transform to lower case
        std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        auto &age = studentAges.at(name); //oops, this will throw an exception if the name isn't found;
        std::cout << name << " is " << age << " years old\n";
        loop = false;
    } catch (const std::out_of_range &e) {
        //We only go inside here if the exception was thrown.
        //if you're curious, e.what() returns a string that you can read.
        std::cout << "why u do dat?" << '\n';
        std::cout << e.what() << '\n';
    }
}
	return 0;
}
