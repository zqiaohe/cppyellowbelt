#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;
// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
     map <string, TasksInfo> Persons;
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
     return Persons.at(person);
  };

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
    ++Persons[person][TaskStatus::NEW];
  };

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {
      //1) приведем task_count к количеству невыполненных задач
      //количество невыполненных задач
      int undone_tasks = Persons[person][TaskStatus::NEW] +
                            Persons[person][TaskStatus::IN_PROGRESS] +
                                Persons[person][TaskStatus::TESTING];
      if (task_count > undone_tasks) { task_count = undone_tasks;}
      //переведем новые задачи
      if (Persons[person][TaskStatus::NEW]<task_count) {
            // переводим задачи в IN_PROGRESS
            Persons[person][TaskStatus::IN_PROGRESS] = Persons[person][TaskStatus::IN_PROGRESS]+
                                                                Persons[person][TaskStatus::NEW];
            //обнуляем новые задачи
            Persons[person][TaskStatus::NEW] = 0;
            //меняем task_count
            task_count = task_count - Persons[person][TaskStatus::NEW];}
      };
};
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}
int main()
{
    TeamTasks Team;
    Team.AddNewTask("Petya");
    PrintTasksInfo(Team.GetPersonTasksInfo("Petya"));

    return 0;
}
