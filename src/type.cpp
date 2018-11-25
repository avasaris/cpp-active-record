#include <active_record/type.h>

namespace ActiveRecord {

// TYPE_LIST
TypeNamePair type_pairs[] = {
  TypeNamePair(Type::integer,        "INTEGER"),
  TypeNamePair(Type::text,           "TEXT"),
  TypeNamePair(Type::floating_point, "FLOAT"),
  TypeNamePair(Type::date,           "DATE")
};

// TYPE_LIST
Type::Type type_list[] = {
  Type::integer,
  Type::text,
  Type::floating_point,
  Type::date
};

TypeNameMap type_name(
  type_pairs,
  type_pairs + sizeof(type_pairs) / sizeof(type_pairs[0])
);

Type::Type index_to_type(int index) {
  type_list[index];
}

// TYPE_LIST
Type::Type to_type(const string& type_name) {
  if(type_name == "INTEGER")
    return Type::integer;
  else if(type_name == "TEXT")
    return Type::text;
  else if(type_name == "FLOAT")
    return Type::floating_point;
  else if(type_name == "DATE")
    return Type::date;
  else
    return Type::unknown;
}

} // namespace ActiveRecord
