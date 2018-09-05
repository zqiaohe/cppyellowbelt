#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;
// ������������ ��� ��� ������� ������
enum class TaskStatus {
  NEW,          // �����
  IN_PROGRESS,  // � ����������
  TESTING,      // �� ������������
  DONE          // ���������
};

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
     map <string, TasksInfo> Persons;
public:
  // �������� ���������� �� �������� ����� ����������� ������������
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
     return Persons.at(person);
  };

  // �������� ����� ������ (� ������� NEW) ��� ����������� �������������
  void AddNewTask(const string& person) {
    ++Persons[person][TaskStatus::NEW];
  };

  // �������� ������� �� ������� ���������� ����� ����������� ������������,
  // ����������� ��. ����
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {
      //1) �������� task_count � ���������� ������������� �����
      //���������� ������������� �����
      int New = Persons[person][TaskStatus::NEW],
          In_progress = Persons[person][TaskStatus::IN_PROGRESS],
          Testing = Persons[person][TaskStatus::TESTING];
      int undone_tasks = New + In_progress + Testing;


      if (task_count > undone_tasks) { task_count = undone_tasks; }
      //��������� ����� ������
      if (task_count - New > 0) {
          task_count = task_count - New;
          Persons[person][TaskStatus::NEW] = 0;
          int New_in_progress = New;
      }
      else {
          if (task_count - New < 0) {
            task_count = 0;
            Persons[person][TaskStatus::NEW] = New - task_count;

      }
//�������
      if (task_count - In_progress > 0) {
          task_count = task_count - In_progress;
          Persons[person][TaskStatus::IN_PROGRESS] = 0;
          Persons[person][TaskStatus::TESTING] = Testing + In_progress;
      }
      else {
          if (task_count - In_progress < 0) {
            task_count = 0;
            Persons[person][TaskStatus::NEW] = New - task_count;
      }
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
