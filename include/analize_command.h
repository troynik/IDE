#include "db.h"
#include "file_system.h"

class Command {
 public:
  virtual ~Command() {};

  virtual std::string getName() const {
      return "Command";
  }

  int RunCommand() const {
      return 0;
  }
};

class MakeContest : public Command {
 public:
  MakeContest(const std::string *params) : contest_name(params[0]), password(params[1]) {};

  virtual ~MakeContest() {};

 public:
  int RunCommand() const {
      CreateFolder();
      AddToDB();
      //Добавление в БД и создание необходимых папок
      return 0;
  }

  virtual std::string GetName() const {
      return "MAKE_CONTEST";
  }

 protected:
  std::string contest_name;
  std::string password;
};

class UpdateContest : public Command {
 public:
  UpdateContest(const std::string *params) : contest_name(params[0]), password(params[1]) {};

  virtual ~UpdateContest() {};

 public:
  int RunCommand() const {
      CheckIfExists();
      //Проверка на наличие констеста и соответствие пароля
      return 0;
  }

  virtual std::string GetName() const {
      return "UPDATE_CONTEST";
  }

 protected:
  std::string contest_name;
  std::string password;
};

class AddProblem : public Command {
 public:
  AddProblem(const std::string *params) : contest_name(params[0]),
                                          password(params[1]),
                                          prog_name(params[2]),
                                          file_path(params[3]),
                                          time_limit(params[4]),
                                          mem_limit(params[5]),
                                          language(params[6]),
                                          additional_params(params[7]) {};

  virtual ~AddProblem() {};

 public:
  int RunCommand() const {
      CheckIfExists();
      CreateFolder();
//    BuildTest();
      //Добалвение в БД, создание необходимых папок и пустых файлов, передача тестов в другой модуль
      return 0;
  }

  virtual std::string GetName() const {
      return "ADD_PROBLEM";
  }

 protected:
  std::string contest_name;
  std::string password;
  std::string prog_name;
  std::string file_path;
  std::string time_limit;
  std::string mem_limit;
  std::string language;
  std::string additional_params;

  int CreateProblemFolder();
};

class DeleteProblem : public Command {
 public:
  DeleteProblem(const std::string *params) : contest_name(params[0]), password(params[1]), prog_name(params[2]) {};

  virtual ~DeleteProblem() {};

 public:
  int RunCommand() const {
      //Удаление из БД и Всех папок
      return 0;
  }

  virtual std::string GetName() const {
      return "DELETE_PROBLEM";
  }

 protected:
  std::string contest_name;
  std::string password;
  std::string prog_name;

  int DeleteProblemFolder();

};

class JoinContest : public Command {
 public:
  JoinContest(const std::string *params) : contest_name(params[0]), user_name(params[1]) {};

  virtual ~JoinContest() {};

 public:
  int RunCommand() const {
      //Добавление участника в контест
      return 0;
  }

  virtual std::string GetName() const {
      return "JOIN_CONTEST";
  }

 protected:
  std::string contest_name;
  std::string user_name;
};

class FinishContest : public Command {
 public:
  FinishContest(const std::string *params) : contest_name(params[0]), password(params[1]) {};

 public:
  int RunCommand() const {
      //Изменение состояния контеста в БД, Генерация общей статистики
      return 0;
  }

  virtual std::string GetName() const {
      return "FINISH CONTEST";
  }

 protected:
  std::string contest_name;
  std::string password;

  virtual std::string SetFinish();

  virtual std::string CreateGeneralStat();
};

class ShowStat : public Command {
 public:
  ShowStat(const std::string *params) : contest_name(params[0]), password(params[1]) {};

 public:
  int RunCommand() const {
      //Получение статистики
      return 0;
  }

  virtual std::string GetName() const {
      return "FINISH CONTEST";
  }

 protected:
  std::string contest_name;
  std::string password;

};

class AddSolution : public Command {
 public:
  AddSolution(const std::string *params) : contest_name(params[0]), prog_name(params[1]), user_name(params[2]), res(params[3]) {};

 public:
  int RunCommand() const {
      //Запись в БД путь с решением и статус
      return 0;
  }

  virtual std::string GetName() const {
      return "ADD SOLUTION";
  }

 protected:
  std::string contest_name;
  std::string prog_name;
  std::string user_name;
  bool res;
};

struct Creator {
  virtual Command *RealizeCommand(const std::string &type, const std::string *params) {
      if (type == "MAKE_CONTEST")
          return new MakeContest(const std::string *params);
      else if (type == "UPDATE_CONTEST")
          return new UpdateContest(const std::string *params);
      else if (type == "ADD_PROBLEM")
          return new AddProblem(const std::string *params);
      else if (type == "DELETE_PROBLEM")
          return new DeleteProblem(const std::string *params);
      else if (type == "JOIN_CONTEST")
          return new JoinContest(
      const std::string *params);
      else if(type == "ADD_SOLUTION") // Приходит от антиплагиата
          return new AddSolution(const std::string *params);
      else if (type == "FINISH_CONTEST")
          return new FinishContest(const std::string *params);
      else if (type == "SHOW_STAT")
          return new ShowStat(const std::string *params);

      return nullptr;
  }
};