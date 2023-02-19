#include <iostream>
#include <ctime>
#include <vector>
#include <string>

enum operation
{
    begin = 0,
    end = 1,
    status = 2,
    ex = 3
};
struct task
{
    std::string name = "";
    std::time_t start = std::time(nullptr);
    std::time_t stop = std::time(nullptr);
    
};



void begin_task(std::vector<task>&);

int main()
{
    std::vector<task> list;
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
                begin_task(list);
                
            }
            else
            {
                list[list.size()-1].stop = std::time(nullptr);
                begin_task(list);
            }
            break;
        case end:
            if (working)
            {
                working = false;
                list[list.size() - 1].stop = std::time(nullptr);
            }
            break;
        case status:
            
            if (working)
            {
                for (int i = 0; i < list.size() - 1; i++)
                {
                    std::cout << i+1 << ". " << list[i].name << std::endl;
                    std::cout << "Wasted time: " << std::difftime(list[i].start, list[i].stop) << std::endl;
                    
                }
                std::cout << "In progress: " << list[list.size()-1].name << std::endl;
            }
            else
            {
                for (int i = 0; i < list.size(); i++)
                {
                    std::cout << i + 1 << ". " << list[i].name << std::endl;
                    std::cout << "Wasted time: " << std::difftime(list[i].start, list[i].stop) << std::endl;

                }

            }


            break;
        case ex:

            return 0;
        }

    }
    
}

void begin_task(std::vector<task>& list)
{
    
    std::string name;
    std::cout << "Enter task's name: " << std::endl;
    std::getline(std::cin, name);
    task in;
    in.name = name;
    in.start = std::time(nullptr);
    list.push_back(in);
    
}
