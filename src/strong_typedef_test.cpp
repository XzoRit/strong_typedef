#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <forward_list>
#include <iterator>
#include <exception>
#include <algorithm>
#include <numeric>
#include <functional>

template<class T, class Tag>
class NamedParameter
{
public:
    explicit NamedParameter(const T& value)
        : m_value(value)
    {}

    operator T() const
    {
        return m_value;
    }
private:
    T m_value;
};

#define NAMED_PARAMETER_TYPE(Name, WrappedType) \
typedef NamedParameter<WrappedType, struct Name##Tag> Name

NAMED_PARAMETER_TYPE(Building, std::string);
NAMED_PARAMETER_TYPE(PointOfCare, std::string);
NAMED_PARAMETER_TYPE(Floor, int);
NAMED_PARAMETER_TYPE(Bed, int);

class Location
{
public:
    Location(
        Building building,
        PointOfCare pointOfCare,
        Floor floor,
        Bed bed)
        : m_building(building)
        , m_pointOfCare(pointOfCare)
        , m_floor(floor)
        , m_bed(bed)
    {}
private:
    std::string m_building;
    std::string m_pointOfCare;
    int m_floor;
    int m_bed;
};

TEST_CASE("ctor of Location")
{
    const Location loc(
        Building("Central"),
        PointOfCare("Intensive Care"),
        Floor(3),
        Bed(12));
}
