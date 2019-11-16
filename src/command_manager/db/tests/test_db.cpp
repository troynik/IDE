#include <gtest/gtest.h>
#include <fstream>
#include "../../../../include/command_manager/db/db.h"


TEST(db, contest) {
    ColumnType CONTEST;
    std::string params[2] = {"Contest Name", "Password"};

    ASSERT_EQ(AddToDB(), 0);
}

TEST(db, solution) {
    ColumnType SOLUTION;
    std::string params[2] = {"Contest Name", "Password"};

    ASSERT_EQ(AddToDB(), 0);
}

TEST(db, member) {
    ColumnType MEMBER;
    std::string params[2] = {"Contest Name", "Password"};

    ASSERT_EQ(DeleteFromDB(), 0);
}


TEST(db, problem) {
    ColumnType PROBLEM;
    std::string params[2] = {"Contest Name", "Password"};

    ASSERT_EQ(CheckIfExists(), 0);
}

int main(int argc, char** argv) {

    return RUN_ALL_TESTS();
}
