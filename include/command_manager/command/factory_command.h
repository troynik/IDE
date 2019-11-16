#include "../db/db.h"
#include "../file_system/file_system.h"

class Command {
 public:
  virtual ~Command() = default;;

  virtual std::string getName() const {
      return "Command";
  }

  virtual int RunCommand(const std::string &command_type, const std::string *params) const {
      return 0;
  }
};

class MakeContest : public Command {
 public:
  explicit MakeContest(const std::string *params) : contest_name(params[0]), password(params[1]) {};

  ~MakeContest() override = default;;

 public:
  int RunCommand(const std::string &command_type, const std::string *params) const override {
//      CreateFolder();
//      AddToDB();
      //Добавление в БД и создание необходимых папок
      return 0;
  }

  std::string getName() const override {
      return "MAKE_CONTEST";
  }

 protected:
  std::string contest_name;
  std::string password;
};

class UpdateContest : public Command {
 public:
  explicit UpdateContest(const std::string *params) : contest_name(params[0]), password(params[1]) {};

  ~UpdateContest() override = default;;

 public:
  int RunCommand(const std::string &command_type, const std::string *params) const override {
//      CheckIfExists();
      //Проверка на наличие констеста и соответствие пароля
      return 0;
  }

  std::string getName() const override {
      return "UPDATE_CONTEST";
  }

 protected:
  std::string contest_name;
  std::string password;
};

class AddProblem : public Command {
 public:
  explicit AddProblem(const std::string *params) : contest_name(params[0]),
                                                   password(params[1]),
                                                   prog_name(params[2]),
                                                   file_path(params[3]),
                                                   time_limit(params[4]),
                                                   mem_limit(params[5]),
                                                   language(params[6]),
                                                   additional_params(params[7]) {};

  ~AddProblem() override = default;;

 public:
  int RunCommand(const std::string &command_type, const std::string *params) const override {
//      CheckIfExists();
//      CreateFolder();
//    BuildTest();
      //Добалвение в БД, создание необходимых папок и пустых файлов, передача тестов в другой модуль
      return 0;
  }

  std::string getName() const override {
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

int AddProblem::CreateProblemFolder() {
    return 0;
}

class DeleteProblem : public Command {
 public:
  explicit DeleteProblem(const std::string *params)
      : contest_name(params[0]), password(params[1]), prog_name(params[2]) {};

  ~DeleteProblem() override = default;;

 public:
  int RunCommand(const std::string &command_type, const std::string *params) const override {
      //Удаление из БД и Всех папок
      return 0;
  }

  std::string getName() const override {
      return "DELETE_PROBLEM";
  }

 protected:
  std::string contest_name;
  std::string password;
  std::string prog_name;

  int DeleteProblemFolder();

};
int DeleteProblem::DeleteProblemFolder() {
    return 0;
}

class JoinContest : public Command {
 public:
  explicit JoinContest(const std::string *params) : contest_name(params[0]), user_name(params[1]) {};

  ~JoinContest() override = default;;

 public:
  int RunCommand(const std::string &command_type, const std::string *params) const override {
      //Добавление участника в контест
      return 0;
  }

  std::string getName() const override {
      return "JOIN_CONTEST";
  }

 protected:
  std::string contest_name;
  std::string user_name;
};

class FinishContest : public Command {
 public:
  explicit FinishContest(const std::string *params) : contest_name(params[0]), password(params[1]) {};

 public:
  int RunCommand(const std::string &command_type, const std::string *params) const override {
      //Изменение состояния контеста в БД, Генерация общей статистики
      return 0;
  }

  std::string getName() const override {
      return "FINISH CONTEST";
  }

 protected:
  std::string contest_name;
  std::string password;

  virtual std::string SetFinish();

  virtual std::string CreateGeneralStat();
};

std::string FinishContest::SetFinish() {
    return std::__cxx11::string();
}

std::string FinishContest::CreateGeneralStat() {
    return std::__cxx11::string();
}

class ShowStat : public Command {
 public:
  explicit ShowStat(const std::string *params) : contest_name(params[0]), password(params[1]) {};

 public:
  int RunCommand(const std::string &command_type, const std::string *params) const override {
      //Получение статистики
      return 0;
  }

  std::string getName() const override {
      return "SHOW STAT";
  }

 protected:
  std::string contest_name;
  std::string password;

};

class AddSolution : public Command {
 public:
  explicit AddSolution(const std::string *params)
      : contest_name(params[0]), prog_name(params[1]), user_name(params[2]), res(params[3]) {};

 public:
  int RunCommand(const std::string &command_type, const std::string *params) const override {
      //Запись в БД путь с решением и статус
      return 0;
  }

  std::string getName() const override {
      return "ADD SOLUTION";
  }

 protected:
  std::string contest_name;
  std::string prog_name;
  std::string user_name;
  std::string res;
};

struct Creator {
  virtual Command *RealizeCommand(const std::string &type, const std::string *params) {
      if (type == "MAKE_CONTEST")
          return new MakeContest(params);
      else if (type == "UPDATE_CONTEST")
          return new UpdateContest(params);
      else if (type == "ADD_PROBLEM")
          return new AddProblem(params);
      else if (type == "DELETE_PROBLEM")
          return new DeleteProblem(params);
      else if (type == "JOIN_CONTEST")
          return new JoinContest(params);
      else if (type == "ADD_SOLUTION") // Приходит от антиплагиата
          return new AddSolution(params);
      else if (type == "FINISH_CONTEST")
          return new FinishContest(params);
      else if (type == "SHOW_STAT")
          return new ShowStat(params);

      return nullptr;
  }
};