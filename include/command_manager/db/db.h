typedef enum {
  PROBLEM,
  CONTEST,
  SOLUTION,
  MEMBER
} ColumnType;

//int CheckIfExists(const ColumnType *col_type, std::string *params);
//
//int AddToDB(const ColumnType *col_type, std::string *params);
//
//int DeleteFromDB(const ColumnType *col_type, std::string *params);

int CheckIfExists();

int AddToDB();

int DeleteFromDB();