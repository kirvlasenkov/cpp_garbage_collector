#include <iostream>
#include <map>

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = std::map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo &GetPersonTasksInfo(const std::string &person) const {
        return PersonTasks.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const std::string &person) {
        auto &tasks_info = PersonTasks[person];
        ++tasks_info[TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const std::string &person, int task_count) {

        TasksInfo UPGRADED;
        TasksInfo UPDATED;
        TasksInfo UNTOUCHED;

        auto &tasks_info = PersonTasks[person];
        for (auto &item : tasks_info) {
            if (item.first == TaskStatus::NEW) {
                if (item.second > 0) {
                    int status = item.second;
                    while (status > 0 && task_count > 0) {
                        ++UPDATED[TaskStatus::IN_PROGRESS];
                        ++UPGRADED[TaskStatus::IN_PROGRESS];
                        --status;
                        --task_count;
                    }
                    if (status > 0) {
                        UNTOUCHED[TaskStatus::NEW] += status;
                        UPGRADED[TaskStatus::NEW] += status;
                    }
                }
            }
            if (item.first == TaskStatus::IN_PROGRESS) {
                if (item.second > 0) {
                    int status = item.second;
                    while (status > 0 && task_count > 0) {
                        ++UPDATED[TaskStatus::TESTING];
                        ++UPGRADED[TaskStatus::TESTING];
                        --status;
                        --task_count;
                    }
                    if (status > 0) {
                        UNTOUCHED[TaskStatus::IN_PROGRESS] += status;
                        UPGRADED[TaskStatus::IN_PROGRESS] += status;
                    }
                }
            }
            if (item.first == TaskStatus::TESTING) {
                if (item.second > 0) {
                    int status = item.second;
                    while (status > 0 && task_count > 0) {
                        ++UPDATED[TaskStatus::DONE];
                        ++UPGRADED[TaskStatus::DONE];
                        --status;
                        --task_count;
                    }
                    if (status > 0) {
                        UNTOUCHED[TaskStatus::TESTING] += status;
                        UPGRADED[TaskStatus::TESTING] += status;
                    }
                }
            }
            if (item.first == TaskStatus::DONE) {
                if (item.second > 0) {
                    UPGRADED[TaskStatus::DONE] += item.second;
                }
            }
        }
        PersonTasks[person] = UPGRADED;
        return std::make_tuple(UPDATED, UNTOUCHED);
    };

private:
    std::map<std::string, TasksInfo> PersonTasks;
};
/*
// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    std::cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
              ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
              ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
              " and " << tasks_info[TaskStatus::DONE] << " tasks are done" << std::endl;
}


int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    std::cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    std::cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    std::cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    std::cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    std::cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    std::cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
} */