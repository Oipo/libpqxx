#include <pqxx/internal/callgate.hxx>

namespace pqxx
{
class connection_base;

namespace internal
{
namespace gate
{
class PQXX_PRIVATE connection_parameterized_invocation :
  callgate<connection_base>
{
  friend class pqxx::internal::parameterized_invocation;

  connection_parameterized_invocation(reference x) : super(x) {}

  result parameterized_exec(
	const PGSTD::string &query,
	const char *const params[],
	const int paramlengths[],
	int nparams)
  {
    return home().parameterized_exec(query, params, paramlengths, nparams);
  }
};
} // namespace pqxx::internal::gate
} // namespace pqxx::internal
} // namespace pqxx
