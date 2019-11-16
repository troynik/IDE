#include <gtest/gtest.h>
#include <fstream>
#include "command/factory_command.h"
#include "../../../../include/command_manager/command/main_command.h"


TEST(analize_command, make_contest_name_run) {
    std::string type = "MAKE_CONTEST";
    std::string params[2] = {"Contest Name", "Password"};

    Creator creator;

    Command *make_contest = creator.RealizeCommand(type,params);

    ASSERT_EQ(make_contest->getName(), type);
    ASSERT_EQ(make_contest->RunCommand(type,params), 0);
}

TEST(analize_command, update_contest_name_run) {
    std::string type = "UPDATE_CONTEST";
    std::string params[2] = {"Contest Name", "Password"};

    Creator creator;

    Command *update_contest = creator.RealizeCommand(type,params);

    ASSERT_EQ(update_contest->getName(), type);
    ASSERT_EQ(update_contest->RunCommand(type,params), 0);

}

TEST(analize_command, add_problem_name_run) {
    std::string type = "ADD_PROBLEM";
    std::string params[4] = {"tests.txt", "time limited", "mem limited", "valgrind"};

    Creator creator;

    Command *add_problem = creator.RealizeCommand(type,params);

    ASSERT_EQ(add_problem->getName(), type);
    ASSERT_EQ(add_problem->RunCommand(type,params), 0);

}

TEST(analize_command, delete_problem_name_run) {
    std::string type = "DELETE_PROBLEM";
    std::string params[1] = {"Prog Name"};

    Creator creator;

    Command *delete_problem = creator.RealizeCommand(type,params);

    ASSERT_EQ(delete_problem->getName(), type);
    ASSERT_EQ(delete_problem->RunCommand(type,params), 0);

}

TEST(analize_command, join_contest_name_run) {
    std::string type = "JOIN_CONTEST";
    std::string params[2] = {"Contest Name", "Nick"};

    Creator creator;

    Command *join_contest = creator.RealizeCommand(type,params);

    ASSERT_EQ(join_contest->getName(), type);
    ASSERT_EQ(join_contest->RunCommand(type,params), 0);

}

TEST(analize_command, finish_contest_name_run) {
    std::string type = "FINISH CONTEST";
    std::string params[2] = {"Contest Name", "Nick"};

    Creator creator;

    Command *join_contest = creator.RealizeCommand(type,params);

    ASSERT_EQ(join_contest->getName(), type);
    ASSERT_EQ(join_contest->RunCommand(type,params), 0);

}

TEST(analize_command, show_stat_name_run) {
    std::string type = "SHOW STAT";
    std::string params[1] = {"Contest Name"};

    Creator creator;

    Command *show_stat = creator.RealizeCommand(type,params);

    ASSERT_EQ(show_stat->getName(), type);
    ASSERT_EQ(show_stat->RunCommand(type,params), 0);

}


TEST(analize_command, add_solution_name_run) {
    std::string type = "ADD SOLUTION";
    std::string params[2] = {"Prog name", "solution_path"};

    Creator creator;

    Command *show_stat = creator.RealizeCommand(type,params);

    ASSERT_EQ(show_stat->getName(), type);
    ASSERT_EQ(show_stat->RunCommand(type,params), 0);

}

TEST(analize_command, make_contest) {
    std::string params[2] = {"Contest Name", "Password"};

    ASSERT_EQ(FuncMakeContest(params), 1);
}

TEST(analize_command, update_contest) {
    std::string params[2] = {"Contest Name", "Password"};

    ASSERT_EQ(FuncUpdateContest(params), 1);
}

TEST(analize_command, add_problem) {
    std::string params[4] = {"tests.txt", "time limited", "mem limited", "valgrind"};

    ASSERT_EQ(FuncAddProblem(params), 1);
}

TEST(analize_command, delete_problem) {
    std::string params[1] = {"Prog Name"};

    ASSERT_EQ(FuncDeleteProblem(params), 1);
}

TEST(analize_command, join_contest) {
    std::string params[2] = {"Contest Name", "Nick"};

    ASSERT_EQ(FuncJoinContest(params), 1);
}

TEST(analize_command, finish_contest) {
    std::string params[2] = {"Contest Name", "Nick"};

    ASSERT_EQ(FuncFinishContest(params), 1);
}


TEST(analize_command, show_stat) {
    std::string params[1] = {"Contest Name"};

    ASSERT_EQ(FuncShowStat(params), 1);
}

TEST(analize_command, add_solution) {
    std::string params[2] = {"Prog name", "solution_path"};

    ASSERT_EQ(FuncAddSolution(params), 1);
}

int main(int argc, char** argv) {

    return RUN_ALL_TESTS();
}
