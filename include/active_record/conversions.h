#include <cstdint>

namespace ActiveRecord {

int64_t string_to_int64(const char* raw, bool& found);
double string_to_double(const char* raw, bool& found);

} // namespace ActiveRecord
