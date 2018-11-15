#include "test_helper.h"
#include "postgresql_connection_test.h"
#include <active_record/connection/postgresql.h>

class PostgresqlTableSetTest : public PostgresqlTest {
 protected:
  virtual void SetUp() {
    created_database_ = "active_record_test_database";
    postgresql_shell_create_database(created_database_, connection_options_);
    connection_options_["database"] = created_database_;
    connection.connect(connection_options_);
   }

  virtual void TearDown() {
    connection.disconnect();
    connection_options_["database"] = "template1";
    postgresql_shell_drop_database(created_database_, connection_options_);
  }

 protected:
  PostgresqlConnection connection;
  string created_database_;
};

TEST_F(PostgresqlTableSetTest, CreateTable) {
  Table td(&connection, "people");

  TableSet::create_table(td);

  // TODO
  //assert_postgresql_table_exists(created_database_, "people", connection_options_);
}
