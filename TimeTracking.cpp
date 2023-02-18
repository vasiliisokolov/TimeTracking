#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <string>

enum operation
{
    begin = 0,
    end = 1,
    status = 2,
    ex = 3
};

std::pair<std::string, std::vector<std::time_t>> begin_task(std::time_t&);

int main()
{
    std::map<std::string, std::vector<std::time_t>> list;
    int op;
    bool working = false;
    std::cout << "Time Management!" << std::endl;
    while (true)
    {
        std::cout << "Choose the operation: ";
        std::cin >> op;
        std::cin.ignore();

        switch (op)
        {
        case begin:
            if (!working)
            {
                working = true;
                std::time_t a = std::time(nullptr);
                list.insert(begin_task(a));
                
            }
            else
            {
                std::time_t b = std::time(nullptr);
                std::map<std::string, std::vector<std::time_t>> ::iterator it = --list.end();
                it->second.push_back(b);
                list.insert(begin_task(b));
            }
            break;
        case end:
            if (working)
            {
                std::time_t b = std::time(nullptr);
                std::map<std::string, std::vector<std::time_t>> ::iterator it = --list.end();
                
                it->second.push_back(b);
            }
            break;
        case status:
            
            if (working)
            {
                int count = 1;
                std::map<std::string, std::vector<std::time_t>> ::iterator it;
                for (it = list.begin(); it != --list.end(); it++)
                {
                    std::cout << count << ". " << it->first << std::endl;
                    std::cout << "Wasted time: " << std::difftime(it->second[0], it->second[1]) << std::endl;
                    count++;
                }
                it = --list.end();
                std::cout << "In progress: " << it->first << std::endl;
            }
            else
            {
                int count = 1;
                std::map<std::string, std::vector<std::time_t>> ::iterator it;
                for (it = list.begin(); it != list.end(); it++)
                {
                    std::cout << count << ". " << it->first << std::endl;
                    std::cout << "Wasted time: " << std::difftime(it->second[0], it->second[1]) << std::endl;
                    count++;
                }

            }


            break;
        case ex:

            return 0;
        }

    }
    
}

std::pair<std::string, std::vector<std::time_t>> begin_task(std::time_t& a)
{
    
    std::vector<std::time_t> in;
    in.push_back(a);
    std::string name;
    std::cout << "Enter task's name: " << std::endl;
    std::getline(std::cin, name);

    return std::make_pair(name, in);
    
}
