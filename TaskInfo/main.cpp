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
      int undone_tasks = Persons[person][TaskStatus::NEW] +
                            Persons[person][TaskStatus::IN_PROGRESS] +
                                Persons[person][TaskStatus::TESTING];
      if (task_count > undone_tasks) { task_count = undone_tasks;}
      //��������� ����� ������
      if (Persons[person][TaskStatus::NEW]<task_count) {
            // ��������� ������ � IN_PROGRESS
            Persons[person][TaskStatus::IN_PROGRESS] = Persons[person][TaskStatus::IN_PROGRESS]+
                                                                Persons[person][TaskStatus::NEW];
            //�������� ����� ������
            Persons[person][TaskStatus::NEW] = 0;
            //������ task_count
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
