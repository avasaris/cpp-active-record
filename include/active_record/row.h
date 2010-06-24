#ifndef _ACTIVE_RECORD_ROW_H_
#define _ACTIVE_RECORD_ROW_H_

#include <active_record/types.h>
#include <sqlite3.h>

namespace ActiveRecord {

class Row {
 public:
  Row(sqlite3_stmt *ppStmt);
  Type get_type(const string &name);
  bool is_type(const string &name, Type type);
  string get_text(const string &name);
  int get_integer(const string &name);
  const AttributeHash& attributes() { return attributes_; };
 private:
  AttributeHash attributes_;
};

typedef vector<Row> RowSet;

} // namespace ActiveRecord

#endif // ndef _ACTIVE_RECORD_ROW_H_