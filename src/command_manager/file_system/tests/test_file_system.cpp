#include <gtest/gtest.h>
#include <fstream>
#include "../../../../include/command_manager/file_system/file_system.h"


TEST(file_system, contest_create) {
    TypeFolder CONTEST_FOLDER;
    std::string params[1] = {"Test"};

    ASSERT_EQ(CreateFolder(), 0);
}

TEST(file_system, contest_delete) {
    TypeFolder CONTEST_FOLDER;
    std::string params[1] = {"Test"};

    ASSERT_EQ(DeleteFolder(), 0);
}

TEST(file_system, solution_create) {
    TypeFolder SOLUTION_FOLDER;
    std::string params[3] = {"Test", "Problem1", "User"};

    ASSERT_EQ(CreateFolder(), 0);
}

TEST(file_system, solution_delete) {
    TypeFolder SOLUTION_FOLDER;
    std::string params[3] = {"Test", "Problem1", "User"};

    ASSERT_EQ(DeleteFolder(), 0);
}

int main(int argc, char** argv) {

    return RUN_ALL_TESTS();
}
