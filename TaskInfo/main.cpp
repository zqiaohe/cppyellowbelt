#include <iostream>
#include <map>
#include <tuple>

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
      TasksInfo updated;
      TasksInfo untouched;
      //1) приведем task_count к количеству невыполненных задач
      //количество невыполненных задач
      int New = Persons[person][TaskStatus::NEW],
          In_progress = Persons[person][TaskStatus::IN_PROGRESS],
          Testing = Persons[person][TaskStatus::TESTING],
          Done = Persons[person][TaskStatus::DONE],
          New_to_in_progress = 0,
          In_progress_to_testing = 0,
          Testing_to_done = 0;
      int undone_tasks = New + In_progress + Testing;

      if (task_count > undone_tasks) { task_count = undone_tasks; }
      //переведем новые задачи
      if (task_count - New > 0) {
          Persons[person][TaskStatus::NEW] = 0;
          New_to_in_progress = New;
          task_count = task_count - New;
      }
      else {
          if (task_count - New < 0) {
            Persons[person][TaskStatus::NEW] = New - task_count;
            New_to_in_progress = task_count;
            task_count = 0;
            }
          else {
            Persons[person][TaskStatus::NEW] = 0;
            New_to_in_progress = task_count;
            task_count = 0;
          }
      }
//in progress
      if (task_count - In_progress > 0) {
          Persons[person][TaskStatus::IN_PROGRESS] = 0;
          In_progress_to_testing = In_progress;
          task_count = task_count - In_progress;
      }
      else {
          if (task_count - In_progress < 0) {
            Persons[person][TaskStatus::IN_PROGRESS] = In_progress - task_count;
            In_progress_to_testing = In_progress - task_count;
            task_count = 0;
            }
          else {
            Persons[person][TaskStatus::IN_PROGRESS] = 0;
            In_progress_to_testing = task_count;
            task_count = 0;
          }
      }

//testing
      if (task_count - Testing > 0) {
          Persons[person][TaskStatus::TESTING] = 0;
          Testing_to_done = Testing;
          task_count = task_count - Testing;
      }
      else {
          if (task_count - Testing < 0) {
            Persons[person][TaskStatus::TESTING] = Testing - task_count;
            Testing_to_done = Testing - task_count;
            task_count = 0;
            }
          else {
            Persons[person][TaskStatus::TESTING] = 0;
            Testing_to_done = task_count;
            task_count = 0;
          }
      }

if (New - New_to_in_progress > 0)
    {untouched[TaskStatus::NEW] = New - New_to_in_progress;}
if (In_progress - In_progress_to_testing > 0)
    {untouched[TaskStatus::IN_PROGRESS] = In_progress - In_progress_to_testing;}
if (Testing - Testing_to_done > 0)
    {untouched[TaskStatus::TESTING] = Testing - Testing_to_done;}
if (New_to_in_progress>0) {updated[TaskStatus::IN_PROGRESS] = New_to_in_progress;}
if (In_progress_to_testing>0) {updated[TaskStatus::TESTING] = In_progress_to_testing;}
if (Testing_to_done>0) {updated[TaskStatus::DONE] = Testing_to_done;}
auto tasks = make_tuple (updated, untouched);
return tasks;
      }

};
// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}

