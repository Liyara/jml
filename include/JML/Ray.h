#ifndef JML_RAY_H
#define JML_RAY_H

#include <JML/Angle.h>
#include <JML/LineSegment.h>

namespace jml {
    class Ray : public Trace<Ray> {
    public:
        Ray(const Vertex &a, const Vertex &b) : Trace(a, b) {

        }

        bool intersects(const LineSegment &r) const {
            return intersects(r, nullptr);
        }

        bool intersects(const LineSegment &r, Vertex *p) const {
            Line l(vA, vB), rl(r.startingPoint(), r.endingPoint());
            Vertex i;
            if (l.intersects(rl, &i)) {
                if (p) *p = i;
                if (hasPoint(i) && r.hasPoint(i)) {
                    if (i == vA || i == r.startingPoint() || i == r.endingPoint()) return endpointIntersectionEnabled();
                    else return true;
                } else return false;
            } else return false;
        }

        bool intersects(const Line &r) const {
            Line l(vA, vB), rl(r.startingPoint(), r.endingPoint());
            Vertex i;
            if (l.intersects(rl, &i)) {
                if (hasPoint(i)) {
                    if (i == vA) return endpointIntersectionEnabled();
                    else return true;
                } else return false;
            } else return false;
        }

        bool intersects(const Ray &r) const {
            Line l(vA, vB), rl(r.vA, r.vB);
            Vertex i;
            if (l.intersects(rl, &i)) {
                if (hasPoint(i) && r.hasPoint(i)) {
                    if (i == vA || i == r.startingPoint()) return endpointIntersectionEnabled();
                    else return true;
                } else return false;
            } else {
                return false;
            }
        }

        bool hasPoint(const Vertex &p) const {
            if (endpointIntersectionEnabled() && p == vA) return true;
            return (compare(static_cast<long double>(angle()), static_cast<long double>(Ray(vA, p).angle())) == JML_EQUAL);
        }

        Angle angle() const {
            return Angle((vA * -1) + vB);
        }

    private:
    };
}

#endif // JML_RAY_H
