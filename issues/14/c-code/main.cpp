#include <iostream>
#include <vector>
#include <map>
#include "math.h"
#include "node/tree.h"

using namespace std;

typedef size_t coord_t;

class Point {
  private:
    coord_t m_x, m_y;
  public:
    /**
     * Default constructor - x and y are 0
     */
    Point() : m_x(0), m_y(0) { }

    /**
     * Construct a point for the given x and y coordinates.
     */
    Point(coord_t x, coord_t y) : m_x(x), m_y(y) {}

    /// Return the x coordinate.
    coord_t x() const {
      return m_x;
    }

    /// Return the y coordinate.
    coord_t y() const {
      return m_y;
    }

    /// Set the x coordinate.
    void x(coord_t x) {
      m_x = x;
    }

    /// Set the y coordinate.
    void y(coord_t y) {
      m_y = y;
    }
    
    /// Move this point by the coordinates x and y (i.e. add (x,y))
    void move(int x, int y) {
      m_x += x;
      m_y += y;
    }

    /// Equality operator
    bool operator==(const Point& x) const {
      return (m_x == x.m_x && m_y == x.m_y);
    }

    /// Inequality operator
    bool operator!=(const Point& x) const {
      return (m_x != x.m_x || m_y != x.m_y);
    }

    /// Less Than operator
    /// (this does not make real sense, but allows Points to be keys in Maps)
    bool operator<(const Point& x) const {
      if (m_x < x.m_x)  return true;
      if (m_y < x.m_y) return true;
      return false;
    }

    /// Addition
    const Point operator+(const Point& p) const {
      return Point(m_x + p.m_x, m_y + p.m_y);
    }
    Point operator+=(const Point& p) {
      m_x += p.m_x;
      m_y += p.m_y;
      return *this;
    }

  };

typedef std::vector<Point> PointVector;
inline bool greater_distance(const Point &origin, const Point &p1, const Point &p2)
{
  double dx2 = (double)p2.x() - origin.x();
  double dx1 = (double)p1.x() - origin.x();
  double dy2 = (double)p2.y() - origin.y();
  double dy1 = (double)p1.y() - origin.y();
  if (dy1 * dy1 + dx1 * dx1 > dy2 * dy2 + dx2 * dx2)
  {
    return true;
  }
  return false;
}

// positive when p0p1 clockwise oriented compared to p0p2
// zero when all points collinear
inline double clockwise_orientation(const Point &p0, const Point &p1, const Point &p2)
{
  return ((double)p1.x() - p0.x()) * ((double)p2.y() - p0.y()) -
         ((double)p2.x() - p0.x()) * ((double)p1.y() - p0.y());
}

inline double polar_angle(Point center, Point p2)
{
  double dx = double(p2.x()) - center.x();
  double dy = double(p2.y()) - center.y();
  return atan2(dy, dx);
};

// see Cormen et al.: Introduction to Algorithms.
// 2nd ed., MIT Press, p. 949, 2001
PointVector *convex_hull_from_points(PointVector *points)
{
  //get leftmost and top point and save it in (*points)[0]
  size_t min_x = points->at(0).x();
  size_t min_y = points->at(0).y();
  size_t min_i = 0;
  size_t i;
  for (i = 0; i < points->size(); i++)
  {
    if (points->at(i).x() < min_x)
    {
      min_x = points->at(i).x();
      min_y = points->at(i).y();
      min_i = i;
    }
    else if (points->at(i).x() == min_x && points->at(i).y() < min_y)
    {
      min_x = points->at(i).x();
      min_y = points->at(i).y();
      min_i = i;
    }
  }
  std::swap(points->at(0), points->at(min_i));

  //sort by polar in polarmap. If more than one point,
  //remove all but the one farthest from origin
  Point origin = points->at(0);
  std::map<double, Point> stack_polarangle;
  std::map<double, Point>::iterator found;
  double polarangle;
  Point p;

  for (PointVector::iterator it = points->begin() + 1; it != points->end(); it++)
  {
    p = *it;
    polarangle = polar_angle(origin, p);
    found = stack_polarangle.find(polarangle);
    //use nearest
    if (found == stack_polarangle.end())
    {
      stack_polarangle[polarangle] = p;
    }
    else if (greater_distance(origin, p, found->second))
    {
      stack_polarangle[polarangle] = p;
    }
  }

  // start with graham scan
  PointVector *retVector = new PointVector;
  std::map<double, Point>::iterator pointIt;
  pointIt = stack_polarangle.begin();

  retVector->push_back(origin); // push point[0]

  retVector->push_back(pointIt->second); // push point[1]
  pointIt++;

  retVector->push_back(pointIt->second); // push point[2]
  pointIt++;

  //pointIt starts at point[3]
  for (; pointIt != stack_polarangle.end(); pointIt++)
  {
    p = pointIt->second;
    while (retVector->size() > 2 && clockwise_orientation(*(retVector->end() - 2), *(retVector->end() - 1), p) <= 0.0)
    {
      retVector->pop_back();
    }
    retVector->push_back(p);
  }

  return retVector;
  }


int main()
{
  PointVector vec;
  /*
  vec.push_back(Point(0, 0));
  vec.push_back(Point(1, 0));
  vec.push_back(Point(2, 0));
  vec.push_back(Point(2, 1));
  vec.push_back(Point(2, 2));
  vec.push_back(Point(1, 3));
  vec.push_back(Point(0, 2));
  vec.push_back(Point(0, 1));
  */
  vec.push_back(Point(0, 0));
  vec.push_back(Point(0, 1));
  vec.push_back(Point(0, 2));
  vec.push_back(Point(0, 3));
  vec.push_back(Point(0, 4));
  vec.push_back(Point(0, 3));
  vec.push_back(Point(0, 2));
  vec.push_back(Point(0, 1));


  PointVector *result = convex_hull_from_points(&vec);
  for (const auto& p : *result) {
    std::cout << p.x() << " " << p.y() << std::endl;
  }
  return 0;
}

