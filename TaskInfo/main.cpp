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

  };

  // �������� ����� ������ (� ������� NEW) ��� ����������� �������������
  void AddNewTask(const string& person) {
    ++Persons[person][TaskStatus::NEW];
  };

  // �������� ������� �� ������� ���������� ����� ����������� ������������,
  // ����������� ��. ����
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count);
};
int main()
{
    TeamTasks Team;
    Team.AddNewTask("Petya");

    return 0;
}
